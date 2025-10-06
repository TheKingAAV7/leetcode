class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>ro={0,0,1,-1};
        vector<int>col={1,-1,0,0};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        // cost,i,j
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
        //priority_queue<array<int,3>>pq;
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto cur=pq.top();pq.pop();
            int cst=cur[0];
            int i=cur[1];
            int j=cur[2];
            if(i==n-1 and j==n-1) return cst;
            for(int k=0;k<4;k++){
                int nx=i+ro[k];
                int ny=j+col[k];
                if(nx>=0 and nx<n and ny>=0 and ny<m){
                    int nd=max(cst,grid[nx][ny]);
                    if(nd<dist[nx][ny]){
                        dist[nx][ny]=nd;
                        pq.push({nd,nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};