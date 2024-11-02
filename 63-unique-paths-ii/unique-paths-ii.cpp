class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(),0));
        if(grid[0][0]==1) return 0;
        int m=grid.size();
        int n= grid[0].size();
       dp[0][0]=1;
       bool f=true;
       for(int i=1;i<m;i++){
        if(grid[i][0]!=1 and f){
        dp[i][0]=1;
        
        }
        else f=false;
       }
       f=true;
       for(int j=1;j<n;j++) {
        if(grid[0][j]!=1 and f){
       dp[0][j]=1;
       
        }
        else f=false;
       }
       for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
             if(grid[i][j]!=1)
            dp[i][j]=dp[i][j-1] + dp[i-1][j];
        }
       }
       return dp[m-1][n-1];
    }
};