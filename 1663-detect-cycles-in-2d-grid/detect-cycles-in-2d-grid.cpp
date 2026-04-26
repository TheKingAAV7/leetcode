class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        function<int(int,int,int,int)>dfs=[&](int i, int j,int parx, int pary)->int{
            vis[i][j]=2;
            // cout<<i<<" "<<j<<endl;
            int ans=0;
            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx==parx and ny==pary) continue;
                if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]==grid[i][j]){
                    if(vis[nx][ny]==2) {
                    // cout<<"CY "<<i<<" "<<j<<" "<<nx<<" "<<ny<<endl;
                    return 1;
                    }
                    if(vis[nx][ny]==0) ans|=dfs(nx,ny,i,j);
                }
            }
            vis[i][j]=1;
            return ans;
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    if(dfs(i,j,-1,-1)) return true;
                    // cout<<endl;
                }
            }
        }
        return false;
    }
};