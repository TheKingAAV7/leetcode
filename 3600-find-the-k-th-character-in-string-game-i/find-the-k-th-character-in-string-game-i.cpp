class Solution {
public:
    char kthCharacter(int k) {
        string ans="a";
        while(ans.length()<k){
            int n=ans.length();
            for(int i=0;i<n;i++){
                if(ans[i]=='z') ans.push_back('a');
                else ans.push_back(ans[i]+1);
            }
        }
        return ans[k-1];
    }
};