class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& v) {
        /*

        Classic Problem

        -> We have to find the maximum possible score for any subgraph for each node..
        ok, let's solve only for the downward direction

        dp[i]-> represents the maximum score for ith node.
        transition
        dp[i]= v[i] + accumulate(dp[child] where dp[child]>=0)


        Now, other possible answers for each node will be
        -> ans[i]= v[parent] + dp[siblings] (>0) + up - dp[i]

        -> parent ka parent..


        */

        for(int &i:v){
            if(i==0) i=-1;
        }

        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>dp(n,INT_MIN);
    

        function<void(int,int)>f1=[&](int node, int par)->void{
            dp[node]= v[node];
            for(auto it:adj[node]){
                if(it==par) continue;
                f1(it,node);
                if(dp[it]>=0) dp[node]+=dp[it];
            }
            return;
        };
        f1(1,-1);
        // for(int i:dp) cout<<i<<" ";
        // cout<<endl;

        vector<int>ans=dp;
        
        function<void(int,int,int)>f=[&](int node, int par, int up)->void{
            
            int sm=0;
            for(auto it:adj[node]){
                if(it!=par) {
                    if(dp[it]>=0)
                    sm+=dp[it];
                }
            }
            
            for(auto it:adj[node]){
                if(it!=par){
                    int sub= (dp[it]>=0)?dp[it]:0;
                    int tmp=sm- sub +up + v[node];
                    ans[it] += (tmp>=0)?tmp:0;
                    f(it,node,max(tmp,0));
                }
            }
            
        };
        

        f(1,-1,0);
        return ans;
        
    }
};