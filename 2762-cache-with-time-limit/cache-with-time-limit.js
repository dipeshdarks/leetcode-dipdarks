class TimeLimitedCache {
    constructor() {
        this.cache = new Map();
    }

    set(key, value, duration) {
        const now = Date.now();
        const exists =
            this.cache.has(key) && this.cache.get(key).expire > now;

        this.cache.set(key, {
            value: value,
            expire: now + duration
        });

        return exists;
    }

    get(key) {
        const now = Date.now();

        if (
            this.cache.has(key) &&
            this.cache.get(key).expire > now
        ) {
            return this.cache.get(key).value;
        }

        return -1;
    }

    count() {
        const now = Date.now();
        let active = 0;

        for (const [key, data] of this.cache) {
            if (data.expire > now) {
                active++;
            }
        }

        return active;
    }
}

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1);           // 42
 * timeLimitedCache.count();          // 1
 */