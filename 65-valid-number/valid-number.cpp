class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;
        bool digitAfterE = true; // only matters if seenE = true

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
                if (seenE) digitAfterE = true;
            }
            else if (c == '.') {
                // dot not allowed after exponent or multiple dots
                if (seenDot || seenE) return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E') {
                // must have digit before e, and only one e
                if (seenE || !seenDigit) return false;
                seenE = true;
                digitAfterE = false; // must find digit after e
            }
            else if (c == '+' || c == '-') {
                // sign only allowed at start or just after e
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else {
                return false;
            }
        }

        return seenDigit && digitAfterE;
    }
};