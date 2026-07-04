class Solution {
public:
    int minScore(int n, vector<vector<int>>& edges) {
        vector<vector<array<int,2>>>adj(n+1);
        for(auto &it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<int>vis(n+1,0);
        int MX=INT_MAX;
        auto f=[&](auto &&self, int node)->void{
          vis[node]=1;
          for(auto &it:adj[node]){
            MX=min(MX,it[1]);
            if(vis[it[0]]==0) self(self,it[0]);
          }
          return;
        };

        f(f,1);
        return MX;
    }
};