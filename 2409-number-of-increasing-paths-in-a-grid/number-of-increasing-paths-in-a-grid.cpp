class Solution {
private:
  int mod=1e9+7;
vector<int>row={-1,1,0,0};
vector<int>col={0,0,-1,1};
void dfs(int i, int j,vector<vector<vector<int>>>&dp,vector<vector<int>>&vis,vector<vector<int>>&deg,vector<vector<int>>&grid,int n, int m){
    if(vis[i][j]) return;
   
    vis[i][j]=1;

    for(int k=0;k<4;k++){
        int newx=i+row[k];
        int newy=j+col[k];
        
        if(newx>=0 and newx<n and newy>=0 and newy<m and   grid[i][j]<grid[newx][newy]){
            
        
            deg[newx][newy]++;
            if(vis[newx][newy]==0){
                
                dfs(newx,newy,dp,vis,deg,grid,n,m);
            }

            int a=dp[newx][newy][k];
            
            
            dp[i][j][k]=dp[newx][newy][4]+1;
            // if(grid[i][j]==1  and i==0 and j==0){
            
            
            // }
        }

    }
    dp[i][j][4]=(dp[i][j][0]+dp[i][j][1]+dp[i][j][2]+dp[i][j][3])%mod;
  //  cout<<i<<" "<<j<<" -> "<<dp[i][j][4]<<endl;
    
    return;

}
public:
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(5,0)));
       vector<vector<int>>vis(n,vector<int>(m,0));
       vector<vector<int>>deg(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    dfs(i,j,dp,vis,deg,grid,n,m);
                }
            }
        }
      //  cout<<endl;
      
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                dp[i][j][4] = (dp[i][j][4] + 1) % mod;  
       
        ans = (ans + dp[i][j][4]) % mod;
            }
           // cout<<endl;
           
        }
        return ans;
    }
};