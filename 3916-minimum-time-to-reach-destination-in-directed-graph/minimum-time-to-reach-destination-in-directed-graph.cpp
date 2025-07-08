class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        priority_queue<vector<int>,vector<vector<int>>, greater<>>pq;
        vector<vector<vector<int>>>adj(n);
        if(n==1) return 0;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2],it[3]});
        }
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        // time, node
        pq.push({0,0});
        while(!pq.empty()){
            int time=pq.top()[0];
            int node=pq.top()[1];
            pq.pop();
        //   cout<<node<<" "<<time<<endl;
            if(node==n-1) return time;
            for(auto it:adj[node]){
                int nd=it[0];
                int st=it[1];
                int et=it[2];
                if(time>et) continue;
                int newdis=time;
                if(time<st){
                    newdis+=(st-time);
                }
                if((newdis+1)<dist[nd]){
                   
                    dist[nd]=newdis+1;
                    pq.push({newdis+1,nd});
                }
            }
        }
        return -1;
    }
};