class Solution {
public:
    void sortColors(vector<int>& a) {
        int l=0, i=0, r=a.size()-1;
        while(i<=r){
            if(a[i]==0) swap(a[l++],a[i++]);
            else if(a[i]==2) swap(a[i],a[r--]);
            else i++;
        }
    }
};