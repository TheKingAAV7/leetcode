class Solution {
private:
void dfs(int node,vector<int>&v,vector<int>&vis,vector<int>&ans,vector<vector<int>>&adj,map<int,int>&mpp){
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
        if(v[it]== -1){
            dfs(it,v,vis,ans,adj,mpp);
        }
        else{
            v[it]+=1;
            if(v[it]== mpp[it]){
                ans.push_back(it);
                dfs(it,v,vis,ans,adj,mpp);
            }
        }
        }
    }
    return;
}
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
      map<string,int>mp;
      map<int,string>mp1;
      map<int,int>mpp;
      int cnt=0;
      vector<int>rec,sup;
      vector<vector<int>>ing;

      for(auto it:recipes){
        if(mp.find(it)==mp.end()){

            mp[it]=cnt;
            mp1[cnt]=it;
            cnt++;
        }
        rec.push_back(mp[it]);
      }
      for(auto it1:ingredients){
        vector<int>tmp;
        for(auto it:it1){
        if(mp.find(it)==mp.end()) {
            mp[it]=cnt;
            mp1[cnt]=it;
            cnt++;
        }
        tmp.push_back(mp[it]);
        }
        ing.push_back(tmp);
      }
      for(auto it:supplies){
        if(mp.find(it)==mp.end()){
            mp[it]=cnt;
            mp1[cnt]=it;
            cnt++;
        }
        sup.push_back(mp[it]);
      }
      int n=mp.size();
      vector<vector<int>>adj(n);
      int m=ing.size();
      for(int i=0;i<m;i++){
        mpp[i]=ing[i].size();
        //cout<<ing[i].size()<<endl;
        for(auto it:ing[i]){
            adj[it].push_back(rec[i]);
        }
      }
      vector<int>ans;
      vector<int>v(n,0),vis(n,0);
      for(auto i:sup){
       v[i]=-1;
      }
      for(auto i:sup){
        if(vis[i]==0){
        dfs(i,v,vis,ans,adj,mpp);
        }
      }
      vector<string>res;
      for(auto i:ans) res.push_back(mp1[i]);
      
      
      return res;
    }
};