class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int ops) {
       
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        for(auto i:nums) mp[i]++; 
         int mn=  nums[0];
        int mx=  nums.back();
        int ans=0;
        for(int i=mn;i<=mx;i++){
            auto it1=lower_bound(nums.begin(),nums.end(),(i-k));
            auto it2=upper_bound(nums.begin(),nums.end(),(i+k));
            it2--;
            int lef=(it1-nums.begin());
            int rig=(it2-nums.begin());
            ans=max(ans,min(rig-lef+1,ops+mp[i]));
        }
        return ans;
    }
};