class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long long num = 0;

        // Read digits
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // Overflow check
            if (sign == 1 && num > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -num < INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * num;
    }
};