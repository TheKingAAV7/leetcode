class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n= grid.size();
        int m= grid[0].size();
        k= min(k,n+m+1);
        int dp[n][m][k+1];
        fill(&dp[0][0][0],&dp[0][0][0]+(n*m*(k+1)),INT_MIN);
        vector<int>cost={0,1,1};
        vector<int>score={0,1,2};
        for(int l=0;l<=k;l++){
        if(l-cost[grid[0][0]]>=0)
        dp[0][0][l-cost[grid[0][0]]]=grid[0][0];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0) continue;
                for(int l=0;l<=k;l++){
                    int up,left;
                    up=left=INT_MIN;
                    // cout<<l-cost[i][j]<<endl;
                    if( (i-1>=0) and (l-cost[grid[i][j]]>=0) and (dp[i-1][j][l-cost[grid[i][j]]]!=INT_MIN)){
                        up= dp[i-1][j][l-cost[grid[i][j]]];
                        dp[i][j][l]= max(dp[i][j][l],grid[i][j]+dp[i-1][j][l-cost[grid[i][j]]]);
                    }
                    if(j-1>=0 and (l-cost[grid[i][j]]>=0) and dp[i][j-1][l-cost[grid[i][j]]]!=INT_MIN){
                        up= dp[i][j-1][l-cost[grid[i][j]]];
                        dp[i][j][l]= max(dp[i][j][l],grid[i][j]+dp[i][j-1][l-cost[grid[i][j]]]);
                    }
                }
            }
        }
        return dp[n-1][m-1][k]==INT_MIN?-1:dp[n-1][m-1][k];
        
    }
};