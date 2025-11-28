class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        /*

        1) we can remove an edge only and only if both the components formed 
        have sm%k==0 
        2) Let's root the tree at a particular node
           we have to make sure that whenever an edge is removed, the 
           condition is satisified..

           we just care if our child edge is satisfying this condition or not..
           if yes remove it , DON"T CARE

           Requirements: 
           1) Subtree sum , which we can get in the dfs only right? yes..
        */
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        function<array<int,2>(int,int)>dfs=[&](int node, int par)->array<int,2>{
           
           int cnt=0;
           int sm=values[node]%k;
           for(auto it:adj[node]){
            if(it!=par){
                array<int,2>tmp=dfs(it,node);
                int cnt1= tmp[0];
                int sm1= tmp[1];
                sm= (sm+sm1)%k;
                cnt+=cnt1;
                if(sm1%k==0){
                   cnt+=1; 
                }
            }
           }
           return {cnt,sm};
        };

       auto ans= dfs(0,-1);
        return ans[0]+1;

    }
};