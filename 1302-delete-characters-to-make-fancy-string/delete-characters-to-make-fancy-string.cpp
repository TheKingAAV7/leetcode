class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(i>=2){
             if(s[i]==ans.back() and s[i]==ans[ans.size()-2]){
                ans.pop_back();
                ans.push_back(s[i]);
             }
             else ans.push_back(s[i]);
            }
            else ans.push_back(s[i]);
        }
        return ans;
    }
};