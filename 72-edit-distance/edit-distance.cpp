class Solution {
public:
    int minDistance(string a, string b) {
        int n=a.size(), m=b.size();
        vector<int> dp(m+1);
        iota(dp.begin(),dp.end(),0);
        for(int i=1;i<=n;i++){
            int prev=dp[0]; dp[0]=i;
            for(int j=1;j<=m;j++){
                int t=dp[j];
                dp[j]=a[i-1]==b[j-1]?prev:1+min({prev,dp[j],dp[j-1]});
                prev=t;
            }
        }
        return dp[m];
    }
};