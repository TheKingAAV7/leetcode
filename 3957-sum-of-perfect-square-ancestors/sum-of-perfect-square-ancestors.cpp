#define ll long long
class Solution {
public:
    static std::vector<int> sieve;
   
    void f(int node, int par, vector<int>&nums,vector<vector<ll>>&adj,vector<ll>&ans, map<ll,ll>&mp){


        ll req=1;
        ll cur_ele=nums[node];
        while(cur_ele>1){
        ll spf=sieve[cur_ele];
        int cnt=0;
        while(cur_ele%spf==0) {
            cur_ele/=spf;
            cnt++;
        }
        if(cnt%2) req*=spf;
        }
        ans[node]=mp[req];
        mp[req]++;
        for(auto it:adj[node]){
            if(it!=par){
                f(it,node,nums,adj,ans,mp);
                
                //cout<<node<<" "<<req<<" "<<mp[req]<<" "<<endl;
            }
        }
       
         
        
        
        mp[req]--;
        //cout<<node<<" "<<mp[req]<<endl;
        return;
        

        return;
    }
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        if(sieve.size()==0){
            sieve.resize(1e5+1,-1);

        for(ll i=2;i<=1e5;i++){
            if(sieve[i]==-1){
                sieve[i]=i;
                for(ll j=i*i;j<=1e5;j+=i){
                    if(sieve[j]==-1) sieve[j]=i;
                }
            }
        }
     
        }
        map<ll,ll>mp;
        vector<vector<ll>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int par=-1;
        vector<ll>ans(n,0);
        f(0,par,nums,adj, ans,mp);
        // for(ll i:ans) cout<<i<<" ";
        // cout<<endl;
        ll res=accumulate(ans.begin(),ans.end(),0ll);
        return res;
    }
};

std::vector<int> Solution::sieve; 