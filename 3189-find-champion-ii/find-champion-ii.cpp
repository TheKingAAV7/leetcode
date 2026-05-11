class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        int sz= edges.size();
        /*

        2->0->1


        */
        
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
         
        }
        vector<int>vis(n,0);
        vector<int>topo;
        auto dfs=[&](auto &&self,int node)->void{
            vis[node]=1;
            for(auto it:adj[node] ){
                if(!vis[it]) self(self,it);
            }
            topo.push_back(node);
        };
         vector<int>dp1(n,0);
        auto dfs2=[&](auto &&self,int node)->void{
            vis[node]=1;
            dp1[node]=1;
            for(auto it:adj[node] ){
                if(!vis[it]) {
                self(self,it);
                dp1[node]+=dp1[it];
                }
            }
        };
        vector<int>dp(n,0);
        auto iscycle=[&](auto &&self, int node)->bool{
            dp[node]=2;
            bool ans=false;
            for(auto it:adj[node]){
                if(dp[it]==0) ans|= self(self,it);
                else if(dp[it]==2) return true;
            }
            dp[node]=1;
            return ans;
        };
        bool cyc=false;
        for(int i=0;i<n;i++){
            if(dp[i]==0){
                cyc|= iscycle(iscycle,i);
            }
        }
        if(cyc) return -1;
        /*
            0->1->2

        */
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(dfs,i);
        }
        reverse(topo.begin(),topo.end());
        
        fill(vis.begin(),vis.end(),0);
       
        for(int i=0;i<n;i++){
            if(!vis[topo[i]]) dfs2(dfs2,topo[i]);
        }
        vector<int>champs;

        for(int i=0;i<n;i++){
            // cout<<dp1[i]<<" ";
            if(dp1[i]==n) {
                champs.push_back(i);
            }
        }
        if(champs.size()>1 || champs.size()==0) 
        return -1;
        return champs[0];
        
    }
};
/*


*/