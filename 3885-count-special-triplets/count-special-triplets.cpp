class Solution {
public:
    int specialTriplets(vector<int>& nums) {
      // 2 1 2 1 2   
      int n=nums.size();
      int mod = 1e9+7;
      int ans=0;
      vector<int>pref(n,0);
      map<int,int>mp,mp1;
      for(int i=0;i<n;i++){
        int req= nums[i]*2;
        pref[i]=mp[req];
        mp[nums[i]]++;
      }
      
      for(int i=n-1;i>=0;i--){
        int req= nums[i]*2;
        int suff= mp1[req];
        long long x= ((1ll*pref[i])%mod * (1ll*suff)%mod)%mod;
        ans=(ans%mod + x%mod )%mod;

        mp1[nums[i]]++;

      }
      return ans;
    }
};