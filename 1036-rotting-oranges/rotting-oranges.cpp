class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        // cost, i, j;
        queue<array<int,3>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) {
                    q.push({0,i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto cur= q.front();
            q.pop();
            int cost= cur[0];
            int i=cur[1];
            int j=cur[2];
            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                
                if(nx>=0 and nx<n and ny>=0 and ny<m){
                    if(grid[nx][ny]==1){
                        int ndist= cost+1;
                        if(ndist<dist[nx][ny]){
                            q.push({ndist,nx,ny});
                            dist[nx][ny]=ndist;
                        }
                    }
                }
            }
        }

        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    if(dist[i][j]==INT_MAX) return -1;
                    ans= max(ans,dist[i][j]);
                }
            }
        }
        return ans==INT_MIN?0:ans;

    }
};