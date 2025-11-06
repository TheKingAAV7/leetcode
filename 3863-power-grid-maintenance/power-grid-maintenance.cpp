class Solution {
public:
    vector<int> processQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& que) {
        vector<vector<int>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }


        
        unordered_map<int,set<int>>mp;
        unordered_map<int,int>nodpar;
        vector<int>vis(n+1,0);
        int par=0;

        function<void(int,int)> dfs=[&](int node, int par)->void{
            vis[node]=1;
            mp[par].insert(node);
            nodpar[node]=par;
            for(auto it:adj[node]){
                if(!vis[it]) dfs(it,par);
            }
            return;
        };

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,par);
                par++;
            }
        }

        // for(auto it:mp){
        //     cout<<it.first<<" : ";
        //     for(int i:it.second) cout<<i<<" ";
        //     cout<<endl;
        // }

        // for(auto it:nodpar){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        vector<int>ans;
        for (auto it:que){
            int op= it[0];
            int nod= it[1];
            if(op==1){
                // if(nodpar.find(nod)==nodpar.end()){
                //     ans.push_back(-1) ;
                //     continue;
                // }
                int parent= nodpar[nod];
               
                if(mp[parent].size() == 0) ans.push_back(-1);
                else{
                    if(mp[parent].find(nod)!=mp[parent].end()){
                        ans.push_back(nod);
                    }
                    else ans.push_back(*(mp[parent].begin()));
                }
            }
            else{
                int parent = nodpar[nod];
                auto cur= mp[parent].find(nod);
                if(cur!=mp[parent].end()){
                 mp[parent].erase(cur);
                 //nodpar.erase(nod);
                }
            }
        }
        return ans;
    }
};