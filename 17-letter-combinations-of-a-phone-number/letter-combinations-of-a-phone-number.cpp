class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void backtrack(string &digits, int index, string &curr) {
        if (index == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {
            curr.push_back(ch);
            backtrack(digits, index + 1, curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        string curr;
        backtrack(digits, 0, curr);

        return ans;
    }
};