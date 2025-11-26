class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m= grid[0].size();
        int MOD=1e9+7;
        int mod=0;
        int dp[n][m][k];
        memset(dp,-1,sizeof(dp));

        function<int(int , int , int )>f= [&](int i ,int j , int mod)->int{
            if(i==n-1 and j==m-1){
                int nmod= (mod+grid[i][j])%k;
                return (nmod==0);
            }
            if(dp[i][j][mod]!=-1) return dp[i][j][mod];
            //if(i>=n || j>=m) return 0;
            int ans=0;
            if(i+1<n)
            ans= (ans + f(i+1,j,(mod+grid[i][j])%k))%MOD;
            if(j+1<m)
            ans= (ans + f(i,j+1,(mod+grid[i][j])%k))%MOD;
           // cout<<ans<<endl;
            return dp[i][j][mod]=ans;
        };
        return f(0,0,mod);
    
    }
};