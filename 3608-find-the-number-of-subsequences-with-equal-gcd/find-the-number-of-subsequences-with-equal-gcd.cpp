class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        const int MAX = 200;

        vector<vector<long long>> dp(MAX + 1,
                                     vector<long long>(MAX + 1, 0));

        dp[0][0] = 1;

        for (int x : nums) {
            auto ndp = dp;

            for (int g1 = 0; g1 <= MAX; g1++) {
                for (int g2 = 0; g2 <= MAX; g2++) {
                    long long cur = dp[g1][g2];
                    if (!cur) continue;

                    int ng1 = (g1 == 0 ? x : std::gcd(g1, x));
                    int ng2 = (g2 == 0 ? x : std::gcd(g2, x));

                    ndp[ng1][g2] = (ndp[ng1][g2] + cur) % MOD;
                    ndp[g1][ng2] = (ndp[g1][ng2] + cur) % MOD;
                }
            }

            dp.swap(ndp);
        }

        long long ans = 0;

        for (int g = 1; g <= MAX; g++)
            ans = (ans + dp[g][g]) % MOD;

        return ans;
    }
};