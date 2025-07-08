class Solution {
private:
void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int pos){
    if(vis[node]!=-1) return ;
    vis[node]=pos;
    for(auto it:adj[node]){
        if(vis[it]==-1) dfs(it,vis,adj,pos);
    }
    return;
}
public:
    vector<int> processQueries(int c, vector<vector<int>>& con, vector<vector<int>>& q) {
        
        vector<vector<int>>adj(c+1);
        for(auto it:con){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(c+1,-1);
       
        int pos=0;
        for(int i=1;i<=c;i++){
            if(vis[i]==-1){
                dfs(i,vis,adj,pos);
                pos++;
            }
        }
        int maxi=*max_element(vis.begin(),vis.end());
        vector<set<int>>v(maxi+1);
        for(int i=1;i<=c;i++){
            v[vis[i]].insert(i);
        }
        for(auto it:v){
            for(auto x:it) cout<<x<<" ";
            cout<<endl;
        }
        vector<int>ans;
        for(auto it:q){
            if(it[0]==1){
                if(v[vis[it[1]]].size()==0) ans.push_back(-1);
                else{
                auto it1=v[vis[it[1]]].find(it[1]);
                if(it1!=v[vis[it[1]]].end()) ans.push_back(it[1]);
                else
                 ans.push_back(*v[vis[it[1]]].begin());
                }
            }
            else{
                auto it1=v[vis[it[1]]].find(it[1]);
                if(it1!=v[vis[it[1]]].end()) v[vis[it[1]]].erase(it1);
            }
        }
        return ans;
        
    }
};