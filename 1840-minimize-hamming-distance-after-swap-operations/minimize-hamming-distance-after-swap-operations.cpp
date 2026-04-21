class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& aS) {
        int n=source.size();
        vector<vector<int>>adj(n);
        for(auto it: aS){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }      

        vector<int>vis(n,0);
        int ans=0;
        function<void(int,vector<int>&,vector<int>&)>dfs=[&](int i, vector<int>&a, vector<int>&b)->void{
          vis[i]=1;
          a.push_back(source[i]);
          b.push_back(target[i]);
          for(auto it:adj[i]){
            if(vis[it]==0) dfs(it,a,b);
          }
        };
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vector<int>a,b;
                dfs(i,a,b);
                // 
                map<int,int>mp;
                for(int &p: a){
                    mp[p]++;
                }
                for(int &p: b){
                    if(mp.find(p)==mp.end()) ans++;
                    else{
                        mp[p]--;
                        if(mp[p]==0) mp.erase(p);
                    }
                }
            }
        }
        return ans;
    }
};