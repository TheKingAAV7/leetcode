class Solution {
private:
void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int par,vector<vector<int>>&ans){
if(vis[node]) return ;
vis[node]=1;
for(auto it:adj[node]){
    if(vis[it]==0){
        dfs(it,vis,adj,par,ans);
    }
}
if(node!=par){
    ans[par].push_back(node);
}
return;
}
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(auto it:pre){
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(i,vis,adj,i,ans);
        }
        vector<bool>res;
        for(auto it:queries){
            int x=it[0];
            int y=it[1];
            bool f=false;
            for(int i:ans[it[0]]){
                if(i==it[1]){
                   f=true;
                   break;
                }
            }
            res.push_back(f);
        }
        return res;
    }
};