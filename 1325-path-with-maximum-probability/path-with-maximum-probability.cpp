class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int ,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pq;
        vector<double>vis(n,0);
        pq.push({1,start});
        while(!pq.empty()){
         auto [x,y]=pq.top();
         pq.pop();
         for(auto it: adj[y]){
            if(x*it.second>vis[it.first]){
                vis[it.first]=x*it.second;
                pq.push({vis[it.first],it.first});
            }
         }

        
        }
        return vis[end];
    }
};