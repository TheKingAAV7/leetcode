class Solution {
private:
void f(int node,vector<set<int>>&adj,vector<int>&vis){
    if(vis[node]==1) return;
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            f(it,adj,vis);
        }
    }
    return;
}
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<set<int>>adj(n+1);
        for(auto it:edges){
           adj[it[0]].insert(it[1]);
           adj[it[1]].insert(it[0]);
        }
        for(int i=n-1;i>=0;i--){
            vector<int>vis(n+1,0);
            adj[edges[i][0]].erase(edges[i][1]);
            adj[edges[i][1]].erase(edges[i][0]);
            f(1,adj,vis);
            bool ff=true;
            for(int j=1;j<=n;j++){
            if(vis[j]==0){
                ff=false;
                break;
            }
            }
            if(ff) return edges[i];
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);

        }
        return {};
    }
};