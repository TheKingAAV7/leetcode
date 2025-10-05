class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        int n=ht.size(),m=ht[0].size();
        
        vector<vector<int>>cnt(n,vector<int>(m,0));
        vector<int>ro={0,0,1,-1};
        vector<int>col={1,-1,0,0};
        auto bfs=[&](char c)->void{
            vector<vector<int>>vis(n,vector<int>(m,0));
            queue<array<int,2>>q;
            if(c=='P'){
                for(int i=0;i<n;i++){
                 vis[i][0]=1;
                 cnt[i][0]++;
                 q.push({i,0});
                }
                for(int j=1;j<m;j++){
                    vis[0][j]=1;
                    cnt[0][j]++;
                 q.push({0,j});
                }
            }
            else{
                for(int i=0;i<n-1;i++){
                    vis[i][m-1]=1;
                    cnt[i][m-1]++;
                 q.push({i,m-1});
                }
                for(int j=0;j<m;j++){ 
                    vis[n-1][j]=1;
                    cnt[n-1][j]++;
                q.push({n-1,j});
                }
            }
            while(!q.empty()){
                auto it=q.front();
                q.pop();
                int x=it[0];
                int y=it[1];
                for(int i=0;i<4;i++){
                    int nx=x+ro[i];
                    int ny=y+col[i];
                    if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0 and ht[nx][ny]>=ht[x][y]){
                        vis[nx][ny]=1;
                        cnt[nx][ny]++;
                        q.push({nx,ny});
                    }
                }
                
            }
            return;
        };

        bfs('P');
        bfs('A');
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(cnt[i][j]==2) ans.push_back({i,j});
            }
        }
        return ans;
    }
};