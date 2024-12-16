class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int ,int>>>adj(n+1);
        for(auto it: times){
         adj[it[0]].push_back({it[1],it[2]});   
        }
        priority_queue<pair<int,int>,vector<pair<int, int>>,greater<pair<int, int>>>pq;
        pq.push({0,k});
        
        vector<int>vis(n+1,INT_MAX);
        vis[k]=0;
        while(!pq.empty()){
            auto [x,y]=pq.top();
            pq.pop();
            for(auto it:adj[y]){
                if(x!=INT_MAX and x+it.second<vis[it.first]){
                    vis[it.first]=x+it.second;
                    pq.push({vis[it.first],it.first});
                }
            }

        }
        int ans=0;
        for(int i=1;i<=n;i++){
            cout<<vis[i]<<" ";
            
            if(vis[i]==INT_MAX) return -1;
            ans=max(ans, vis[i]);
        }

        return ans;
    }
};