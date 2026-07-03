/**
 * @param {Generator} generator
 * @return {[Function, Promise]}
 */
var cancellable = function(generator) {
    let cancelled = false;

    const cancel = () => {
        cancelled = true;
    };

    const promise = new Promise((resolve, reject) => {

        function step(nextFn, value) {
            let result;

            try {
                result = nextFn.call(generator, value);
            } catch (err) {
                reject(err);
                return;
            }

            if (result.done) {
                resolve(result.value);
                return;
            }

            Promise.resolve(result.value)
                .then(val => {
                    if (cancelled) {
                        step(generator.throw, "Cancelled");
                    } else {
                        step(generator.next, val);
                    }
                })
                .catch(err => {
                    step(generator.throw, err);
                });
        }

        step(generator.next, undefined);
    });

    return [cancel, promise];
};