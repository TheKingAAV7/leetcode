class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(char c:s){
            if(c>='a' and c<='z'){
                ans.push_back(c);
            }
            else if(c=='*'){
                if(ans.size()>0) ans.pop_back();
            }
            else if(c=='#'){
                ans+=ans;
            }
            else reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};