#define ll long long
class Solution {
public:
    
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        
        // vector<vector<int>>dp0(n,vector<int>(n,INT_MAX));
        // vector<vector<int>>dp1(n,vector<int>(n,INT_MAX));
        ll dp[n][n][2];
       
        fill(&dp[0][0][0], &dp[0][0][0] + n*n*2, LLONG_MAX);
      
        
        vector<vector<array<ll,4>>>adj(n);
        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2],it[3]});
            adj[it[1]].push_back({it[0],it[2],it[3]});
        }
        auto dij=[&](int &source,int tx)->void{
            // cost, node
            priority_queue<array<ll,2>,vector<array<ll,2>>,greater<array<ll,2>>>pq;
            pq.push({0,source});
            dp[source][source][tx]=0;
            while(!pq.empty()){
                auto cur= pq.top();pq.pop();
                ll cost= cur[0];
                ll node= cur[1];
                if(dp[source][node][tx]!=cost) continue;
                for(auto &it:adj[node]){
                    ll nod= it[0];
                    ll cst= it[1];
                    ll tax= it[2];

                    if(tx){
                        ll ncost= cost+cst*tax;
                        if(ncost<dp[source][nod][1]){
                            dp[source][nod][1]=ncost;
                            pq.push({ncost,nod});
                        }
                    }
                    else{
                        // cout<<cost<<" "<<cst<<endl;
                        ll ncost= cost+cst;
                        if(ncost<dp[source][nod][0]){
                            dp[source][nod][0]=ncost;
                            pq.push({ncost,nod});
                        }
                    }
                }
            }
            return;
        };

        for(int i=0;i<n;i++){
            dij(i,0);
            dij(i,1);
        }
        
        vector<int>ans(n,INT_MAX);
        for(int i=0;i<n;i++){
            ll val=LLONG_MAX;
            for(int j=0;j<n;j++){
                if(dp[i][j][0]!=LLONG_MAX and dp[j][i][1]!=LLONG_MAX){
                ll cur= prices[j]+dp[i][j][0] + dp[j][i][1];
                val= min(cur,val);
                }
            }
            ans[i]=val;
        }
        return ans;

    }
};