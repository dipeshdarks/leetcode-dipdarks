class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long result = 0;

        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            while ((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            result += multiple;
        }

        // Determine sign
        if ((dividend < 0) ^ (divisor < 0))
            result = -result;

        return (int)result;
    }
};