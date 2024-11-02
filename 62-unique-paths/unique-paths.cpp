class Solution {
private: 
int f(int i, int j, int m, int n,vector<vector<int>>&dp){
    if(i==m-1 and j==n-1) return 1;
    if(i>=m || j>=n ) return 0;
    if(dp[i][j]!=-1) return dp[i][j]; 
    int down=f(i+1, j, m, n,dp);
    int right= f(i, j+1, m, n,dp);
    return dp[i][j]=down+right;
}
public:
    int uniquePaths(int m, int n) {
       vector<vector<int>>dp(m, vector<int>(n,-1));
       return f(0, 0, m,n,dp);
    }
};