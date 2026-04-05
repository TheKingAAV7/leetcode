class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        //  X = y^grid[i][j]
        int n=grid.size();
        int m=grid[0].size();
        
       
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(1024,0)));
        dp[0][0][grid[0][0]]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0) continue;
                for(int x=0;x<=1023;x++){
                    if(i-1>=0)
                     dp[i][j][x]|= dp[i-1][j][x^grid[i][j]];
                     if(j-1>=0)
                     dp[i][j][x]|=dp[i][j-1][x^grid[i][j]];
                }
            }
        }
        for(int i=0;i<=1023;i++) {
            if(dp[n-1][m-1][i]==1) return i;
        }
        return -1;
    }
};