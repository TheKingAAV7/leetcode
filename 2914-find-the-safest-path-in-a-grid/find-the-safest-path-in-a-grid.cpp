class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n= grid.size();

        int lo=1, hi= n*n;
        int ans=0;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        auto f=[&](int x)->bool{
         vector<vector<int>>mat= grid;
         queue<array<int,3>>q;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                 q.push({i,j,0});
                }
            }
         }
         while(!q.empty()){
            auto cur= q.front();
            q.pop();
            int i= cur[0];
            int j= cur[1];
            int lvl= cur[2];
            if(lvl==x-1) continue;
            for(int k=0;k<4;k++){
                int nx= i+dx[k];
                int ny= j+dy[k];
                if(nx>=0 and nx<n and ny>=0 and ny<n and mat[nx][ny]==0){
                    mat[nx][ny]=1;
                    q.push({nx,ny,lvl+1});
                }
            }
         }
         // path validation
         while(!q.empty()) q.pop();
         if(mat[0][0]==1 || mat[n-1][n-1]==1) return false;
         q.push({0,0,0});
         mat[0][0]=1;
         while(!q.empty()){
            auto cur= q.front(); q.pop();
            int i= cur[0];
            int j= cur[1];
            if(i==n-1 and j==n-1) return true;
            for(int k=0;k<4;k++){
            int nx= i+dx[k];
            int ny= j+dy[k];
            if(nx>=0 and nx<n and ny>=0 and ny<n and mat[nx][ny]==0){
                q.push({nx,ny,0});
                mat[nx][ny]=1;
            }
            }
         }
         return false;
        };
        while(lo<=hi){
            int mid= (lo+hi)>>1;
            if(f(mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi= mid-1;
        }
        return ans;
    }
};