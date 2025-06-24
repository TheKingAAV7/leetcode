class Solution {
public:
    int minMoves(vector<string>& grid, int ener) {
        int n=grid.size();
        int m=grid[0].size();
        queue<array<int,5>>q;
        static bool vis[20][20][1<<10][51];
        
        char c='a';
        int tl=0;
        int si,sj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L') {
                    tl++;
                    grid[i][j]=c;
                    c++;
                }
                if(grid[i][j]=='S'){
                    si=i;
                    sj=j;
                }
            }
        }
        int BM=(1<<tl);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int ma=0;ma<BM;ma++){
                    for(int e=0;e<=ener;e++){
                        vis[i][j][ma][e]=false;
                    }
                }
            }
        }
        
        // i, j, bm,energy
        // i, j, bm, cnt,energy;
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        q.push({si,sj,0,0,ener});
        vis[si][sj][0][ener]=1;
        while(!q.empty()){
            int i=q.front()[0];
            int j=q.front()[1];
            int bm=q.front()[2];
            int cnt=q.front()[3];
            int energy=q.front()[4];
            q.pop();

            if(bm==(BM-1)){
                return cnt;
            }
            if(energy==0 and grid[i][j]!='R') continue;
            for(int k=0;k<4;k++){
                int nx=i+row[k];
                int ny=j+col[k];
                if(nx>=0 and nx<n and ny>=0 and ny<m){
                    if(grid[nx][ny]=='X') continue;
                    if(grid[nx][ny]=='S' || grid[nx][ny]=='.'){
                        if(!vis[nx][ny][bm][energy-1]){
                            q.push({nx,ny,bm,cnt+1,energy-1});
                            vis[nx][ny][bm][energy-1]=1;
                        }
                    }
                    else if(grid[nx][ny]=='R'){
                        int new_ener=ener;  // d
                        if(!vis[nx][ny][bm][new_ener]){
                             vis[nx][ny][bm][new_ener]=1;
                            q.push({nx,ny,bm,cnt+1,new_ener});
                           
                        }
                    }
                    else if(grid[nx][ny]>='a' and grid[nx][ny]<='j'){
                        int tmp=grid[nx][ny]-'a';
                        if((bm>>tmp)&1){
                            //alrady taken
                            if(!vis[nx][ny][bm][energy-1]){
                                vis[nx][ny][bm][energy-1]=1;
                                q.push({nx,ny,bm,cnt+1,energy-1});
                            }
                        }
                        else{
                           int newbm= bm|(1<<tmp);
                           if(!vis[nx][ny][newbm][energy-1]){
                            vis[nx][ny][newbm][energy-1]=1;
                            q.push({nx,ny,newbm,cnt+1,energy-1});
                           }

                        }
                    }
                }
            }
        }
        return -1;
        
    }
};