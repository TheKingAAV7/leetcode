class Solution {
public: 
    vector<int>dp;
    vector<int>topo;

    void dfs(int node,vector<int>&vis,vector<vector<pair<int,int>>>&adj){
        if(vis[node]) return ;
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it.first]==0)
            dfs(it.first,vis,adj);
        }
        topo.push_back(node);
        return;
    }

   
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        /*
            DAG
            find a path with exactly k edges
            find its sum 
            find the maximum sum <t

            run a topo sort , we will get the ordering.
            now, for each node, run a function which returns all the nodes
            which are k distance apart run a bfs..
            or even dfs looks fine..
            to find sum, do a precalculation of prefix sm;;

        */

        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
            dfs(i,vis,adj);
            }
        }
        reverse(topo.begin(),topo.end());
        // for(int i:topo) cout<<i<<" ";
        // cout<<endl;

        

        auto f=[&](int node)->vector<array<int,2>>{
            
            set<array<int,3>>vis1;
            queue<array<int,3>>q;
            
            
            q.push({node,0,0});
            vector<array<int,2>>ans;
            vis1.insert({node,0,0});
            while(!q.empty()){
                auto x=q.front();q.pop();
                int nd=x[0];
                int ed=x[1];
                int sm=x[2];
                if(ed==k) {
                    ans.push_back({nd,sm});
                    continue;
                }
                for(auto [it,wt]:adj[nd]){
                    array<int,3>ntmp={it,ed+1,sm+wt};
                    if(vis1.find(ntmp)==vis1.end()){
                        q.push({it,ed+1,sm+wt});
                        vis1.insert(ntmp);
                    }
                }
            }
            return ans;
            
        };
        int fans=-1;
        fill(vis.begin(),vis.end(),0);
        for(int i=0;i<n;i++){
            vector<array<int,2>>knodes=f(topo[i]);
            //cout<<topo[i]<<endl;
            for(auto [x,y]:knodes) {
                if(y<t)
                fans=max(fans,y);
            }

            

        }

        return fans;
        
    }
};

/*




*/