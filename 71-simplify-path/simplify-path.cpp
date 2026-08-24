class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s; string x;
        stringstream ss(path);
        while(getline(ss,x,'/')){
            if(x.empty()||x==".") continue;
            if(x==".."){ if(!s.empty()) s.pop_back(); }
            else s.push_back(x);
        }
        string ans="/";
        for(int i=0;i<s.size();i++) ans+=s[i]+(i+1<s.size()?"/":"");
        return ans;
    }
};