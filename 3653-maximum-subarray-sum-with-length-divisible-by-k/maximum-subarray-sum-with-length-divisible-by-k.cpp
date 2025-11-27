
#define ll long long
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,ll>mp;
        ll sm=0;
        int curmod=0;
        mp[curmod]=0;
        ll ans=LLONG_MIN;
        for(int i=0;i<n;i++){
            curmod=(curmod+1)%k;
            sm+=nums[i];
            if(mp.find(curmod)!=mp.end()){
                ans= max(ans,sm-mp[curmod]);
            }
            if(mp.find(curmod)==mp.end()) mp[curmod]= sm;
            else mp[curmod] = min(mp[curmod], sm);
        }
        return ans;
    }
};