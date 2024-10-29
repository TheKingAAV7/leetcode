class Solution {
private: 
int f(vector<vector<int>>&grid, vector<vector<int>>&vis, int i, int j,int prev){
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]<=prev) return -1;
    if(vis[i][j]!=0) return vis[i][j];
    int right, ur,dr;
    right= 1 + f(grid, vis, i,j+1,grid[i][j]);
    ur=   1+  f(grid, vis, i+1,j +1, grid[i][j]);
    dr= 1+ f(grid, vis, i-1,j+1,grid[i][j]);
    
    // cout<<right<<" "<<ur<<" "<<dr<<endl;
    // if(right==1) cout<<i<<" k"<<j<<endl;
    return vis[i][j]=max(right, max(ur,dr));
    
}
public:
    int maxMoves(vector<vector<int>>& grid) {
      int ans=0;
      int cnt=0;
      vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));

      for(int i=0;i<grid.size();i++){
        
            ans= max(ans, f(grid,vis,i,0,-1));
       
      }
      return ans;  
    }
};