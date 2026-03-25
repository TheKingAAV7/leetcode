class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
         vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>v(n,0);
        vector<int>height(n,0);
        function<int(int,int)>f=[&](int node, int par)->int{
          
          int mx=0;
          for(auto it:adj[node]){
              if(it!=par){
                  int curht= f(it,node);
                  mx=max(mx,curht);
              }
          }
          v[node]=max(v[node],1+mx);
          return height[node]=1+mx;
        };
        
        function<void(int,int,int)>f1=[&](int node, int par,int upmx)->void{
         /*
         store {ht,it} in set
         find answer for child node..
         
         v[child]= {1+upmx,max(other children's height)+1}
         return max(upmx,max(other children's height))
         */
         
         v[node]=max(v[node],upmx);
         upmx++;
         set<array<int,2>>st;
         map<int,int>mp;
         for(auto it:adj[node]){
             if(it!=par){
                 st.insert({height[it],it});
                 mp[it]=height[it];
             }
         }
         for(auto it:adj[node]){
             if(it!=par){
                 array<int,2>todel={mp[it],it};
               
                 st.erase(todel);
                 
                 int lst=0;
                 if(st.size()>0)
                 lst=(*prev(st.end()))[0];
                 f1(it,node,max(upmx,lst+1));
                 st.insert(todel);
             }
         }
         return;
        };
        
        f(0,-1);
        for(int &i:v) i--;
        // for(int i:v) cout<<i<<" ";
        // cout<<endl;
        f1(0,-1,0);   
        // for(int i:v) cout<<i<<" ";
        // cout<<endl;
        int mn=*min_element(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(v[i]==mn) ans.push_back(i);
        }
        return ans;
        
    }
};