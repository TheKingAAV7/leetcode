class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<array<int,2>>>adj(n),revadj(n);
        /*
        0-> {{1,2},{2,1},{3,5}}

        */
        for(auto &it:edges){
            int u= it[0];
            int v= it[1];
            int w= it[2];
            adj[u].push_back({v,w});
            revadj[v].push_back({u,2*w});
        }
        // cost,node 
        vector<int>dist(n,INT_MAX);
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pq; 

        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            auto cur= pq.top();
            pq.pop();
            int cost= cur[0];
            int node= cur[1];

            if(node==n-1) return cost;
            // either reverse one of edges and traverse it , or traverse the other          nodes normally

            // traverse normal edges first
            for(auto it:adj[node]){
                int nei= it[0];
                int wt= it[1];
                int newcost= cost+wt;
                if(newcost<dist[nei]){
                    dist[nei]=newcost;
                    pq.push({newcost,nei});
                }
            }

            // traverse reversed edges
            for(auto it:revadj[node]){
                int nei=it[0];
                int wt= it[1];
                int newcost= cost+wt;
                if(newcost<dist[nei]){
                    dist[nei]= newcost;
                    pq.push({newcost,nei});
                }
            }

        }
        return -1;
    }
};