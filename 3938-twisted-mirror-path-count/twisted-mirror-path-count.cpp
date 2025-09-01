class Solution {
private:
int mod=1e9+7;
vector<vector<int>>dp;
int f(int i, int j,vector<vector<int>>&grid,int n, int m){
    if(i<0 || i>=n || j<0 || j>=m) return 0;
    if(i==n-1 and j==m-1) return 1;
   
    int ans=0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(grid[i][j]==0){
            // mov right
            int i1=i,j1=j+1;
        if(i1>=0 and i1<n and j1>=0 and j1<m and grid[i1][j1]==0) ans=(ans%mod+f(i1,j1,grid,n,m)%mod);
        else{
            bool r=true;
            i1++;
            while(i1>=0 and i1<n and j1>=0 and j1<m and grid[i1][j1] ){
                if(r){
                    j1++;
                }
                else{
                    i1++;
                }
                r=!r;
            }
            ans=(ans%mod+f(i1,j1,grid,n,m)%mod)%mod;
        }

     i1=i+1,j1=j;
        if(i1>=0 and i1<n and j1>=0 and j1<m and grid[i1][j1]==0) ans=(ans%mod+f(i1,j1,grid,n,m)%mod);
        else{
            bool d=true;
            j1++;
            while(i1>=0 and i1<n and j1>=0 and j1<m and grid[i1][j1] ){
                if(d){
                    i1++;
                }
                else{
                    j1++;
                }
                d=!d;
            }
            ans=(ans%mod+f(i1,j1,grid,n,m)%mod)%mod;
        }
    }
    return dp[i][j]= ans%mod;

}
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        int ans=f(0,0,grid,n,m);

        return ans%mod;
    }
};