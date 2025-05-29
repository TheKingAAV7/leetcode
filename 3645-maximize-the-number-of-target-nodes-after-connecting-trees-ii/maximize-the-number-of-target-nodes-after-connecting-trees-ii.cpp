class Solution {
private:
void f(vector<vector<int>>&adj,vector<pair<int,int>>&v,int n,vector<int>&vis ){
queue<pair<int,int>>q;

q.push({0,0});
int even=0,odd=0;
while(!q.empty()){
    int node=q.front().first;
    int parity=q.front().second;
    vis[node]=1;
    if(parity){
        vis[node]=1;
        odd++;
    }
    else {
        vis[node]=2;
        even++;
    }
    q.pop();
    for(auto it:adj[node]){
        if(!vis[it])
        q.push({it,!parity});
    }
}
 //cout<<even<<" "<<odd<<endl;
  v[0]={even,odd};
  for(int i=1;i<n;i++){
    if(vis[i]%2==0) v[i]={even,odd};
    else v[i]={odd,even};
  }
  return;

}
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<pair<int,int>>v1(n),v2(m);
        vector<vector<int>>adj1(n),adj2(m);
        for(auto it:edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for(auto it:edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        vector<int>vis1(n,0),vis2(m,0);
        f(adj1,v1,n,vis1);
        f(adj2,v2,m,vis2);
        int od=0,ev=0;
       // cout<<endl;
        for(int i=0;i<m;i++){
          //  cout<<v2[i].first<<" "<<v2[i].second<<endl;
            od=max(v2[i].second,od);
        }
        for(int i=0;i<m;i++){
            ev=max(ev,v2[i].first);
        }
        
        
        // cout<<endl;
        // cout<<od<<"-> "<<ev<<endl;

        // for(auto it:v1) cout<<it.first<<" "<<it.second<<endl;
        // cout<<endl;

        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
          ///  cout<<vis1[i]<<" ";
        if(vis1[i]%2){
            ans[i]=v1[i].first+ev;
        }
        else ans[i]=v1[i].first+od;
        }
      //  cout<<endl;
        return  ans;
    }
};