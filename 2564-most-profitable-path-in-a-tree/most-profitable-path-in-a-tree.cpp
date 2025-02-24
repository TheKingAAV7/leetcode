class Solution {
private:
bool dfs(int node, vector<vector<int>>&adj,vector<int>&tmp,vector<int>&vis){
    if(vis[node]){
        return false;
    }
    if(node==0){
        tmp.push_back(0);
        return true;
    }
    vis[node]=1;

    bool f=false;
    for(auto it:adj[node]){
       f|=dfs(it,adj,tmp,vis);
    }
    if(f) tmp.push_back(node);
    return f;
    


}
void f1(int node,vector<vector<int>>&adj,vector<int>&amt,long long cost,long long &ans,vector<int>&vis){
    
    
    vis[node]=1;
    
    bool flag=true;
    for(auto it:adj[node]){
       if(vis[it]==0){
        f1(it,adj,amt,cost+amt[node],ans,vis);
        flag=false;
       }
    }
   
    
    if(flag) {
   //   cout<<node<<" "<<cost+amt[node]<<endl;   
    ans=max(ans,cost+amt[node]);
    }
    return ;
}
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>tmp;
        vector<int>vis(n,0);
       
        dfs(bob,adj,tmp,vis);
        reverse(tmp.begin(),tmp.end());
       
        if(tmp.size()%2==0){
            for(int i=0;i<tmp.size()/2;i++){
                amount[tmp[i]]=0;
            }
        }
        else{
            for(int i=0;i<tmp.size()/2;i++) amount[tmp[i]]=0;
            amount[tmp[tmp.size()/2]]/=2;
        }
        //  for(int i:amount) cout<<i<<" ";
        // cout<<endl;

        fill(vis.begin(),vis.end(),0);
        long long ans=INT_MIN;
        f1(0,adj,amount,0,ans,vis);
        return ans;
        
    }
};