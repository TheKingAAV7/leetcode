class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>lvl(n,0);
        vector<int>dp(n,0);

        vector<vector<int>>ans;
        vector<int>isbridge(n,0);

        function<void(int,int,int)>dfs=[&](int node,int level,int par)->void{
            lvl[node]=level;
            
            for(auto nei:adj[node]){
                if(lvl[nei]==0){
                    dfs(nei,level+1,node);
                    dp[node]+=dp[nei];
                }
                else if(lvl[nei]>lvl[node]){
                    // going down => subtrack
                    dp[node]--;
                }
                else{
                    // going up => add
                    dp[node]++;
                }
            }
            dp[node]--;
            if(lvl[node]>1 and dp[node]==0){
                ans.push_back({par,node});
            }
            return;
          
        };
        for(int i=0;i<n;i++){
            if(!lvl[i]){
                dfs(i,1,-1);
            }
        }
       
        return ans;

        



    }
};