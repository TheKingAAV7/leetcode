class Solution {
private:
void f(int node,vector<vector<int>>&adj,vector<int>&time,vector<int>&vis,int cnt,int par){
    if(vis[node]==1) return;
    vis[node]=1;
    time[node]=cnt;
    for(auto it:adj[node]){
        if(vis[it]==0){
            f(it,adj,time,vis,cnt+1,node);
        }
        if(it!=par){
            time[node]=min(time[node],time[it]);
        }
    }

    return;

}
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>time(n+1,0),vis(n+1,0);
        int cnt=1;
        f(1,adj,time,vis,cnt,-1);
        for(int i=n-1;i>=0;i--){
            if(time[edges[i][0]]==time[edges[i][1]]) return edges[i];
        }
        return {};
    }
};