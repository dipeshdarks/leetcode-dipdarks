class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);

        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        vector<bool> vis(26, false);
        string st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (vis[c - 'a'])
                continue;

            while (!st.empty() &&
                   st.back() > c &&
                   last[st.back() - 'a'] > i) {
                vis[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            vis[c - 'a'] = true;
        }

        return st;
    }
};