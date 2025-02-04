class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // ntake;
                if(i-1>=0) dp[i][j]=max(dp[i][j],dp[i-1][j]);
                if(j-1>=0) dp[i][j]=max(dp[i][j],dp[i][j-1]);

                if(s[i]==t[j]){
                    if(i-1>=0 and j-1>=0)
                    dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
                    else dp[i][j]=max(dp[i][j],1);
                }
            }
        }
        return dp[n-1][m-1];
        
    }
};