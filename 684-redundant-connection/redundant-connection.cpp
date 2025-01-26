class Solution {
private:
void f(int node,vector<int>&vis,vector<int>&time,vector<int>adj[],int cnt,int par){
    vis[node]=1;
    time[node]=cnt;
    for(auto it:adj[node]){
        if(vis[it]==0){
            f(it,vis,time,adj,cnt+1,node);
        }
    }
    for(auto it:adj[node]){
        if(it!=par){
            time[node]=min(time[it],time[node]);
        }
    }
    return;

}
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>adj[n+1];
       vector<int>vis(n+1,0);
       vector<int>time(n+1,1e9);
       for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
       }
       int cnt=0;
       f(1,vis,time,adj,cnt,-1);
       for(int i=n-1;i>=0;i--){
        auto it=edges[i];
        if(time[it[0]]==time[it[1]]) return it;
       }
        return {};
    }
};