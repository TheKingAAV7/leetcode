class Solution {
private:
void dfs(int node,vector<vector<int>>&adj,vector<int>&disc,vector<int>&low,int &cnt,vector<int>&vis,int parent,vector<vector<int>>&ans){
    disc[node]=cnt;
    low[node]=cnt;
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            ++cnt;
         //   cout<<it<<endl;
            dfs(it,adj,disc,low,cnt,vis,node,ans);
        }
    }
    for(auto it:adj[node]){
        if(it!=parent){
            low[node]=min(low[it],low[node]);
        }
    }
    if(parent!=-1){
        if(disc[parent]<low[node]){
            ans.push_back({parent,node});
        }
    }
    return;
}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>>ans;
        vector<vector<int>>adj(n);
        
        for(auto it: con){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>disc(n,-1),low(n,INT_MAX);
        int cnt=1;
        vector<int>vis(n,0);
        int parent=-1;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
        dfs(i,adj,disc,low,cnt,vis,parent,ans);
            }
        }
        return ans;
    }
};