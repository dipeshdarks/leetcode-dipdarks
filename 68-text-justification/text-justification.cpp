class Solution {
public:
    vector<string> fullJustify(vector<string>& w, int m) {
        vector<string> a; int i=0;
        while(i<w.size()){ int j=i+1,l=w[i].size();
            while(j<w.size()&&l+1+w[j].size()<=m) l+=1+w[j++].size();
            int g=j-i-1,s=m-(l-g); string x=w[i];
            if(j==w.size()||!g) { for(int k=i+1;k<j;k++) x+=" "+w[k]; x+=string(m-x.size(),' '); }
            else for(int k=i+1;k<j;k++) x+=string(s/g+(k-i<=s%g),' ')+w[k];
            a.push_back(x); i=j;
        } return a;
    }
};