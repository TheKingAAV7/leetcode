class Solution {
public:
    bool isSubstringPresent(string s) {
        int n=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
                }
                maxi=max(dp[i][j],maxi);
            }
        }
        return maxi>=2;
    }
};