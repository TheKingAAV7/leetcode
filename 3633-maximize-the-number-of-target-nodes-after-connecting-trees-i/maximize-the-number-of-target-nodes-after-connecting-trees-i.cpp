class Solution {
private:
void f(int n,vector<vector<int>>&adj,int k,vector<int>&ans){
   
    for(int i=0;i<n;i++){
        int cnt=0;
        queue<pair<int,int>>q;
        vector<int>vis(n,0);
        q.push({i,0});
        vis[i]=1;
        while(!q.empty()){
            int node=q.front().first;
            int tmp=q.front().second;
            if(tmp<=k) cnt++;
            q.pop();
            vis[node]=1;
            for(auto it:adj[node]){
              
                if(vis[it]==0){
                    
                    q.push({it,tmp+1});
                }
            }
            
        }
     //   cout<<cnt<<endl;
        ans[i]=cnt;

    }
    return ;
}
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int maxi=0;
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<vector<int>>adj1(n),adj2(m);
        for(auto it:edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
         for(auto it:edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        vector<int>v1(n),v2(m);
        f(n,adj1,k,v1);
      //  cout<<endl;
        f(m,adj2,k-1,v2);
        maxi=*max_element(v2.begin(),v2.end());
        for(int &i:v1){
            i=i+maxi;
        }
        return v1;

        
    }
};