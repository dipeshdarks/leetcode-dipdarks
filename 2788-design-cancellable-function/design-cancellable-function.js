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
                // If cancelled, throw "Cancelled" into generator
                if (cancelled) {
                    result = generator.throw("Cancelled");
                    cancelled = false;
                } else {
                    result = nextFn.call(generator, value);
                }
            } catch (err) {
                reject(err);
                return;
            }

            const { value: yielded, done } = result;

            if (done) {
                resolve(yielded);
                return;
            }

            Promise.resolve(yielded)
                .then(
                    val => step(generator.next, val),
                    err => step(generator.throw, err)
                );
        }

        step(generator.next, undefined);
    });

    return [cancel, promise];
};