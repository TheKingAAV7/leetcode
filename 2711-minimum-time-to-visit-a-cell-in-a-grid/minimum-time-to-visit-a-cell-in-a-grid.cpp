#define ll long long
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        priority_queue<vector<ll>,vector<vector<ll>>,greater<>>pq;
        vector<int>row={-1,1,0,0};
        vector<int>col={0,0,-1,1};
        int n=grid.size(),m=grid[0].size();
        vector<vector<ll>>dist(n,vector<ll>(m,LLONG_MAX));
        if (n > 1 && m > 1
    && grid[0][1] > 1
    && grid[1][0] > 1)
  return -1;
        // time, i, j
        pq.push({0,0,0});
        dist[0][0]=0;
        while(!pq.empty()){
            ll tim=pq.top()[0];
            ll i=pq.top()[1];
            ll j=pq.top()[2];
            if(i==n-1 and j==m-1) return tim;
            pq.pop();
            for(int k=0;k<4;k++){
                ll nx=i+row[k];
                ll ny=j+col[k];
                if(nx>=0 and nx<n and ny>=0 and ny<m){
                    ll newdist=tim+1;
                    if(newdist<grid[nx][ny]){
                      ll wait = grid[nx][ny];
  if ((wait - newdist) % 2 == 1) 
    wait++;           // bump one more second if the gap is odd
  newdist = wait;
                    }
                    if(newdist<dist[nx][ny]){
                        dist[nx][ny]=newdist;
                        pq.push({newdist,nx,ny});
                    }
                }
            }
        }

        return -1;
    }
};