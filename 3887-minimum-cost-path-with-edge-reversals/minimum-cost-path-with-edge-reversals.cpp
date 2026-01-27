class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<array<int,2>>>adj(n),revadj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            revadj[it[1]].push_back({it[0],2*it[2]});
        }
        // dist,node,flag
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
        vector<vector<int>>vis(n,vector<int>(2,INT_MAX));
        pq.push({0,0,0});
        pq.push({0,0,1});
        vis[0][0]=0;
        vis[0][1]=0;
        while(!pq.empty()){
            auto cur= pq.top();
            pq.pop();
            int dist= cur[0];
            int node= cur[1];
            int flag= cur[2];
           // cout<<dist<<" "<<node<<" "<<flag<<endl;
            if(node==n-1) return dist;

            for(auto it:adj[node]){
                int nei= it[0];
                int wt= it[1];
                if(dist+wt<vis[nei][flag]){
                    vis[nei][flag]=dist+wt;
                    pq.push({dist+wt,nei,flag});
                }
            }
          //  if(flag) continue;
            for(auto it:revadj[node]){
                int nei=it[0];
                int wt= it[1];
               // cout<<node<<" "<<nei<<" "<<wt<<" "<<dist<<endl;
                if(dist+wt<vis[nei][1]){
                    vis[nei][1]=dist+wt;
                    pq.push({dist+wt,nei,1});
                }
            }
        }
        return -1;
    }
};