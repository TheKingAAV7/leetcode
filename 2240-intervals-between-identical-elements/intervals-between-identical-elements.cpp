#define ll long long
class Solution {
public:
   /*

   (i-j1) + (i-j2)

   */
    vector<long long> getDistances(vector<int>& nums) {
        int n= nums.size();
        vector<ll>ans(n,0);
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto [x,v]:mp){
            int sz= v.size();
            // for(int i:v) cout<<i<<" ";
            // cout<<endl;
            ll sm=0ll;
            for(int i=0;i<sz;i++){
                ll cnt= i+1ll;
                sm+=v[i];
                ans[v[i]]+=(1ll*v[i]*cnt)- (sm);
            }
            // for(int i:ans) cout<<i<<" ";
            // cout<<endl;
            sm=0ll;
            for(int i=sz-1;i>=0;i--){
                ll cnt= sz-i;
                sm+=v[i];
                ans[v[i]]+=sm - (1ll*cnt*v[i]);
            }
            // for(int i:ans) cout<<i<<" ";
            // cout<<endl;
        }
        return ans;
    }
};