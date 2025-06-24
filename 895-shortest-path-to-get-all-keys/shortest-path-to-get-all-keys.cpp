class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        queue<vector<int>>q;
        int tk=0;
        int si=-1,sj=-1;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
             if(grid[i][j]>='a' and grid[i][j]<='f') tk++;
             if(grid[i][j]=='@') {
                si=i;
                sj=j;
             }
            }
        }
        int BM=(1<<tk);
        vector<int>row={-1,1,0,0};
        vector<int>col={0,0,-1,1};
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(BM+1,0)));
        // i , j, bm
        q.push({si,sj,0,0});
        vis[si][sj][0]=1;
        while(!q.empty()){
            int i=q.front()[0];
            int j=q.front()[1];
            int bm=q.front()[2];
            int cnt=q.front()[3];
            q.pop();
            if(bm==(BM-1)) return cnt;
            for(int k=0;k<4;k++){
                int nx=row[k]+i;
                int ny=col[k]+j;
                if(nx>=0 and nx<n and ny>=0 and ny<m){
                    if(grid[nx][ny]=='#') continue;
                    if(grid[nx][ny]>='A' and grid[nx][ny]<='F'){
                        int req=grid[nx][ny]-'A';
                        if((bm>>req)&1){
                            if(!vis[nx][ny][bm]){
                                vis[nx][ny][bm]=1;
                                q.push({nx,ny,bm,cnt+1});
                            }
                        }
                        else continue;
                    }
                    else if(grid[nx][ny]=='.' || grid[nx][ny]=='@'){
                        if(!vis[nx][ny][bm]){
                            vis[nx][ny][bm]=1;
                            q.push({nx,ny,bm,cnt+1});
                        }
                    }
                    else if(grid[nx][ny]>='a' and grid[nx][ny]<='f'){
                        int keyy=grid[nx][ny]-'a';
                        int new_bm= bm|(1<<keyy);
                        if(!vis[nx][ny][new_bm]){
                        q.push({nx, ny, new_bm ,cnt+1});
                        vis[nx][ny][new_bm]=1;
                        }
                    }
                }
            }
            
        }

        return -1;

        
    }
};