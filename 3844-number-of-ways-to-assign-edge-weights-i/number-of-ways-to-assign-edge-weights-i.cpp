class Solution {
private:
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,int &maxi,int cnt){
if(vis[node]==1) return;
vis[node]=1;
maxi=max(maxi,cnt);
for(auto it:adj[node]){
dfs(it,adj,vis,maxi,cnt+1);
}
return;
}
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1,0);
        int maxi=0;
        dfs(1,adj,vis,maxi,0);
        int mod=1e9+7;
        int ans= binpow(2,maxi-1,mod);
        return ans;
    }
};