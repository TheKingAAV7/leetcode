class DSU{

public:
vector<int>rank,parent;
DSU(int n){
    rank.resize(n,0);
    parent.resize(n);
    for(int i=0;i<n;i++) parent[i]=i;
}
int find(int i){
    if(parent[i]==i) return i;
    return parent[i]=find(parent[i]);
}
void uni(int i, int j){
    int ipar=find(i);
    int jpar=find(j);
    if(ipar==jpar) return;
    if(rank[ipar]<rank[jpar]){
        parent[ipar]=jpar;
    }
    else if(rank[ipar]>rank[jpar]) {
        parent[jpar]=ipar;
    }
    else{
        parent[jpar]=ipar;
        rank[ipar]++;
    }
}

};


class Solution {
private:
void dfs(int node, vector<vector<int>>&mp,vector<int>&vis,vector<vector<pair<int,int>>>&adj, DSU &ds){
    vis[node]=1;
    for(auto it:adj[node]){
        int pari=ds.find(it.first);
        if(mp[pari].size()==0){
        mp[pari].push_back(it.second);
        }
        else{
           int tmp= mp[pari].back();
           mp[pari].pop_back();
            mp[pari].push_back((it.second&tmp));
        }
        if(vis[it.first]==0){
            
            dfs(it.first,mp,vis,adj,ds);
        }
    }
    return;
}
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>>mp(n);
        vector<vector<pair<int,int>>>adj(n);
        vector<int>ans;
        DSU ds(n);
        for(auto it:edges){
          ds.uni(it[0],it[1]);
         adj[it[0]].push_back({it[1],it[2]});
         adj[it[1]].push_back({it[0],it[2]});   
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
           // cout<<ds.parent[i]<<" ";
            if(vis[i]==0){
                dfs(i,mp,vis,adj,ds);
            }
        }
        //cout<<endl;
        for(auto it:query){
            int x=ds.find(it[0]);
            int y=ds.find(it[1]);
            if(x==y){
                int tmp=mp[x].back();
                ans.push_back(tmp);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};