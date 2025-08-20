class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int x=INT_MAX,y=INT_MAX;
                if(i+1<n){
                x=dp[i+1][j];
                dp[i][j]=min(dp[i][j],grid[i][j]+x);
                }
                if(j+1<m){
                 y=dp[i][j+1];
                 dp[i][j]=min(dp[i][j],grid[i][j]+y);
                }
            }
        }
        return dp[0][0];
        


        
    }
};