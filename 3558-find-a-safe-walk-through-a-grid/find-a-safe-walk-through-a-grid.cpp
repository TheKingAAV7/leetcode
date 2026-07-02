class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
      int n= grid.size();
      int m= grid[0].size();

      vector<vector<int>>vis(n,vector<int>(m,INT_MAX));
      // h ,i , j
      
      int dx[4]={1,-1,0,0};
      int dy[4]={0,0,1,-1};
      deque<array<int,3>>dq;
      if(grid[0][0]){
      dq.push_back({1,0,0});
      vis[0][0]=1;
      }
      else{ 
      dq.push_back({0,0,0});
      vis[0][0]=0;
      }

      while(!dq.empty()){
        auto cur= dq.front(); dq.pop_front();
        int h= cur[0];
        int i= cur[1];
        int j= cur[2]; 
        if(h>=health) continue;
        if(i==n-1 and j==m-1){

          
            return true;
        }
        for(int k=0;k<4;k++){
          int nx=i+dx[k];
          int ny=j+dy[k];
          if(nx>=0 and nx<n and ny>=0 and ny<m){
            if(h+grid[nx][ny]<health and (h+grid[nx][ny]<vis[nx][ny])){
                vis[nx][ny]=h+grid[nx][ny];
                if(grid[nx][ny]) dq.push_back({h+1,nx,ny});
                else dq.push_front({h,nx,ny});
            }
          }
        }
      }

      

      return false;
     


    }
};