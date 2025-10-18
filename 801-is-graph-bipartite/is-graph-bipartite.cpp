class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        function<void(int node,int par)>dfs=[&](int node,int par){
            if(vis[node]!=0) {
                if(vis[node]==2 || vis[node]==1){
                    if(vis[node]!=par)
                    vis[node]=3;
                }
                else vis[node]=par;
                return;
            }
            vis[node]=-1;
            int npar=(par==1)?2:1;
            for(auto it:graph[node]){
                dfs(it,npar);
            }
            return ;
        };
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,1);
            }
        }
        // for(int i:vis) cout<<i<<" ";
        // cout<<endl;
        for(int i:vis) if(i==3) return false;

        return true;
        
    }
};