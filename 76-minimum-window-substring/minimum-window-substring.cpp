class Solution {
public:
    string minWindow(string s, string t) {
        int cnt[128]={}, need=t.size(), l=0, start=0, best=INT_MAX;
        for(char c:t) cnt[c]++;
        for(int r=0;r<s.size();r++){
            if(cnt[s[r]]>0) need--;
            cnt[s[r]]--;
            while(need==0){
                if(r-l+1<best) best=r-l+1,start=l;
                if(++cnt[s[l++]]>0) need++;
            }
        }
        return best==INT_MAX ? "" : s.substr(start,best);
    }
};