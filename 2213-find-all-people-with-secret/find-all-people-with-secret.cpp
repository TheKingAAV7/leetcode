class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& edges, int fP) {

        
        vector<vector<array<int,2>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[2],it[1]});
            adj[it[1]].push_back({it[2],it[0]});
        }
        for(int i=0;i<n;i++){
            sort(adj[i].begin(),adj[i].end());
            //sort(adj[it[1]].begin(),adj[it[1]].end());
        }

     
        // vector<int>vis(n,0);
        // function<void(int,int)>f=[&](int node, int time)->void{
        //     vis[node]=1;
        //     for(auto it:adj[node]){
        //         int nod= it[1];
        //         int rt= it[2];
        //         if(time<=rt){
        //             if(!vis[nod]){
        //                 dfs(nod,rt);
        //             }
        //         }
        //     }
        // };

        vector<int>dist(n,INT_MAX);
        // time, node
        //vector<int>vis(n,0);
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pq;
        pq.push({0,fP});
        pq.push({0,0});
        dist[0]=0;
        dist[fP]=0;
        
      
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int tim= cur[0];
            int node= cur[1];
            // cout<<node<<endl;
            //if(tim>dist[node]) continue;
            for(auto it:adj[node]){
                int nei= it[1];
                int reqtime=it[0];
                
                // cout<<node<<" "<<nei<<endl;
                if(tim<=reqtime){
                    
                    if(reqtime<dist[nei]){
                    dist[nei]=reqtime;
                    
                    pq.push({reqtime,nei});
                    }
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(dist[i]!=INT_MAX) ans.push_back(i);
        }
        
        return ans;
        

    }
};