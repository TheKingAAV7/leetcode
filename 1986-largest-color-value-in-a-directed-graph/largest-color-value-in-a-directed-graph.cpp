class Solution {
private:
bool dfsDirected(int node, vector<bool>& visited, vector<bool>& recStack, const vector<vector<int>>& adj) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfsDirected(neighbor, visited, recStack, adj)) return true;
        } else if (recStack[neighbor]) {
            return true;  // Cycle detected
        }
    }

    recStack[node] = false;
    return false;
}

bool hasCycleDirected(int n, const vector<vector<int>>& adj) {
    vector<bool> visited(n, false), recStack(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfsDirected(i, visited, recStack, adj)) return true;
        }
    }
    return false;
}

void f(int node,vector<vector<int>>&dp,vector<vector<int>>&adj,int n,vector<int>&vis,string &colors){
    if(vis[node]) return ;
     vis[node]=1;

    
    for(auto it:adj[node]){
        if(vis[it]==0){
           f(it,dp,adj,n,vis,colors);
        }
        for(int j=0;j<26;j++){
            dp[node][j]=max(dp[node][j],dp[it][j]);
        }
    }
     dp[node][colors[node]-'a']++;
     return;
}
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>>adj(n);
        for(auto it:edges) adj[it[0]].push_back(it[1]);
        if(hasCycleDirected(n,adj)) return -1;
        vector<vector<int>>dp(n,vector<int>(26,0));
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        f(i,dp,adj,n,vis,colors);

        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++) ans=max(ans,dp[i][j]);
        }
        return ans;

    }
};