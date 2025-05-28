class Solution {
private:
void dfs(int node, vector<vector<int>>&adj,vector<int>&vis, int cnt,vector<int>&v){
    if(vis[node]) return ;
    vis[node]=1;
    v[node]=max(v[node],cnt);
    for(auto it:adj[node]){
        dfs(it,adj,vis, cnt+1,v);
    }
    return; 
}
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
            adj[i].push_back(edges[i]);
        }
        vector<int>vis(n,0);
        vector<int>v1(n,-1),v2(n,-1);
        v1[node1]=0;
        v2[node2]=0;
        dfs(node1,adj,vis,0,v1);
        fill(vis.begin(),vis.end(),0);
        dfs(node2,adj,vis,0,v2);

        // for(int i:v1) cout<<i<<" ";
        // cout<<endl;
        // for(int i:v2) cout<<i<<" ";
        // cout<<endl;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(v1[i]!=(-1) and v2[i]!=(-1))
            mini=min(mini,max(v1[i],v2[i]));
        }
        for(int i=0;i<n;i++) {
            if(max(v1[i],v2[i])==mini) return i;
        }

        return -1;
    }
};