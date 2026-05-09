class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n= grid.size();
        int m= grid[0].size();
        // vector<vector<int>>ans(n,vector<int>(m,0));
        
        vector<int>ro={1,0,-1,0};
        vector<int>col={0,1,0,-1};
        
        vector<vector<int>>vis(n,vector<int>(m,0)),vis2(n,vector<int>(m,0));

        auto dfs2=[&](auto &&self, int i, int j, vector<int>&v,int dir,int &idx)->void{
            // cout<<i<<" "<<j<<endl;
            if(vis2[i][j]) return;
            grid[i][j]=v[idx++];
            vis2[i][j]=1;
            int ni= i+ro[dir];
            int nj= j+col[dir];
            if(ni>=0 and ni<n and nj>=0 and nj<m and vis2[ni][nj]==0){
                self(self,ni,nj,v,dir,idx);
            }
            else{
                // cout<<"YSE"<<endl;
                if(dir==3) return;
                dir= (dir+1)%4;
                int nx= i+ro[dir];
                int ny= j+col[dir];
                // cout<<i<<" "<<j<<" "<<nx<<" "<<ny<<endl;
                if(nx>=0 and nx<n and ny>=0 and ny<m and vis2[nx][ny]==0){
                self(self,nx,ny,v,dir,idx);
                }
            }
            return;
        };

        auto dfs=[&](auto &&self, int i, int j, vector<int>&cur,int dir)->void{
            // cout<<i<<" "<<j<<endl;
            if(vis[i][j]) return;
            cur.push_back(grid[i][j]);
            vis[i][j]=1;
            int ni= i+ro[dir];
            int nj= j+col[dir];
            if(ni>=0 and ni<n and nj>=0 and nj<m and vis[ni][nj]==0){
                self(self,ni,nj,cur,dir);
            }
            else{
                // cout<<"YSE"<<endl;
                if(dir==3) return;
                dir= (dir+1)%4;
                int nx= i+ro[dir];
                int ny= j+col[dir];
                // cout<<i<<" "<<j<<" "<<nx<<" "<<ny<<endl;
                if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0){
                self(self,nx,ny,cur,dir);
                }
            }
            return;
        };
        
        int rounds= min(n,m)/2;
        // cout<<rounds<<endl;
        for(int i=0;i<rounds;i++){
            vector<int>cur;
      
            dfs(dfs,i,i,cur,0);
            int sz= cur.size();
            vector<int>v(sz);
            for(int i=0;i<sz;i++){
                int nxtidx= (i+k)%sz;
                v[nxtidx]=cur[i];
            }
            int id=0;

            dfs2(dfs2,i,i,v,0,id);
            

        }

        return grid;

    }
};