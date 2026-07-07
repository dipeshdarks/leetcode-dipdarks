class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;

        // Form x using non-zero digits
        int temp = n;
        vector<int> digits;

        if (temp == 0)
            return 0;

        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }

        reverse(digits.begin(), digits.end());

        for (int d : digits) {
            if (d != 0)
                x = x * 10 + d;
        }

        // If all digits were zero
        if (x == 0)
            return 0;

        long long sum = 0;
        long long t = x;
        while (t > 0) {
            sum += t % 10;
            t /= 10;
        }

        return x * sum;
    }
};