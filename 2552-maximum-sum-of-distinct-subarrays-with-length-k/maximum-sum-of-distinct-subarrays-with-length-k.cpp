class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int, int>mp;
        int l=0;
        long long sm=0;
        long long ans=0;
        for(int i=0;i<k;i++){
            sm+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()==k) ans= max(ans,sm);
      
        for(int j=k;j<nums.size();j++){
            mp[nums[j-k]]--;
            if(mp[nums[j-k]]==0)mp.erase(nums[j-k]);
            mp[nums[j]]++;
            sm-=nums[j-k];
            sm+=nums[j];
            if(mp.size()==k) ans=max(ans, sm);

        }
        return ans;

    }
};