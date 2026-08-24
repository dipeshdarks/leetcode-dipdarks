class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int m=a.size(), n=a[0].size(), l=0, r=m*n-1;
        while(l<=r){
            int x=l+(r-l)/2, v=a[x/n][x%n];
            if(v==t) return true;
            if(v<t) l=x+1;
            else r=x-1;
        }
        return false;
    }
};