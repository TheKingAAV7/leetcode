class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]=='1'){
                    dp[i][j]=1+min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
                    ans=max(ans,dp[i][j]*dp[i][j]);
                }
            }
        }
        return ans;
        
    }
};