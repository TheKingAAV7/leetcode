class Solution {
public:
    int specialTriplets(vector<int>& nums) {
      // 2 1 2 1 2   
      int n=nums.size();
      int mod = 1e9+7;
      int ans=0;
      vector<int>pref(n,0),suff(n,0);
      map<int,int>mp;
      for(int i=0;i<n;i++){
        int req= nums[i]*2;
        pref[i]=mp[req];
        mp[nums[i]]++;
      }
      mp.clear();
      for(int i=n-1;i>=0;i--){
        int req= nums[i]*2;
        suff[i]= mp[req];
        long long x= ((1ll*pref[i])%mod * (1ll*suff[i])%mod)%mod;
        ans=(ans%mod + x%mod )%mod;

        mp[nums[i]]++;

      }
      return ans;
    }
};