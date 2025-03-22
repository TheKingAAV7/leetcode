class Solution {
private:
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<set<int>>&mp,int &cnode,int &cedges){
    vis[node]=1;
    for(auto it:adj[node]){
        if(mp[node].find(it)==mp[node].end()){
           
            mp[node].insert(it);
            mp[it].insert(node);
            cedges++;
        }
        if(vis[it]==0){
            cnode+=1;
            dfs(it,adj,vis,mp,cnode,cedges);
        }
    }
    return;
}
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        int ans=0;
        vector<vector<int>>adj(n);
        vector<set<int>>mp(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            
            if(vis[i]==0){
                int cnode=1;
                int cedges=0;
                dfs(i,adj,vis,mp,cnode,cedges);
                if(cedges==((cnode*(cnode-1))/2))  ans++;
            }
        }
        return ans;
    }
};