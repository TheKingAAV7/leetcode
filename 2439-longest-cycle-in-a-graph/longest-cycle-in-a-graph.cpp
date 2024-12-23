class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
            adj[i].push_back(edges[i]);
        }
        
        vector<int>vis(n,0);
        vector<int>tim(n,INT_MAX);
        vector<int>cyc(n,-1);

        auto dfs=[&](auto self,int node, int cur,int &maxi,int cy)->void{
         if(vis[node]) return;
         vis[node]=1;
         tim[node]=cur;
         cyc[node]=cy;
         maxi= max(maxi,cur+1);
         
         for(auto it:adj[node]){
           if(vis[it]==0){
            self(self,it,cur+1,maxi,cy);
           
           }
            if(cyc[it]==cyc[node])
            tim[node]=min(tim[node],tim[it]);
            
         }
         
         return;
         

        };


        int cur=0;
        int cy=0;
        for(int i=0;i<n;i++){
           // int maxi=cur;
            if(vis[i]==0){
                int maxi=cur;
                dfs(dfs,i,cur,maxi,cy);
                cur=maxi;
                cy++;
               // cout<<cur<<endl;
               
            }
           
        }
        map<int,int>mp;
        for(int i:tim) mp[i]++;
        int ans=1;
        for(auto [x,y]: mp){
            ans=max(y,ans);
        }
        if(ans==1) return -1;
         return ans;
    }
};