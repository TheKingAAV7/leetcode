
#define ll long long
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int mod=1e9+7;
        int n=nums.size();
        vector<ll>pref(n,0);
        vector<int>dp(n,0);
        vector<int>idx(n,0);
        // iota(idx.begin(),idx.end(),0);
        map<int,int>mp;
        int l=0;
        for(int i=0;i<n;i++){
           mp[nums[i]]++;
            while(((mp.rbegin()->first)-(mp.begin()->first))>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            idx[i]=l;
        }
        dp[0]=1;
        pref[0]=1;
       
        for(int i=1;i<n;i++){
           
            if(idx[i]==0){
               dp[i]=(pref[i-1]+1)%mod;
            }
            else{
                if(idx[i]==1){
                    dp[i]=pref[i-1]%mod;
                }
                else
                dp[i]=(pref[i-1]-pref[idx[i]-2]+mod)%mod;
            }
            
            pref[i]=(pref[i-1]%mod+dp[i]%mod)%mod;
        }
     
        return dp[n-1];
    }
};