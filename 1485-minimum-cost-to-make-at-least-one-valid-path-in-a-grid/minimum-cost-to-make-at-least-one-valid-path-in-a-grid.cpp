class Solution {

private:
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
bool val(int x, int y, int rows, int cols){
    if(x>=0 and x<rows and y>=0 and y<cols) return true;
    return false;
}
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid[0].size(),n=grid.size();
        pair<int,int>start={0,0};
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        pq.push({0,start});
        while(!pq.empty()){
            auto [d,pos]=pq.top();
            int x=pos.first,y=pos.second;
            pq.pop();
            if(x==n-1 and y==m-1){
                return d;
            }
            if(d>dist[x][y]) continue;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(val(nx,ny,n,m)){
                    int newDist=0;
                    if(grid[x][y]==(i+1)){
                        newDist=d;
                    }
                    else{
                        newDist=d+1;
                    }
                    if(newDist<dist[nx][ny]){
                        dist[nx][ny]=newDist;
                        pq.push({newDist,{nx,ny}});
                    }
                }
            }
            

        }
        return -1;

        
    }
};