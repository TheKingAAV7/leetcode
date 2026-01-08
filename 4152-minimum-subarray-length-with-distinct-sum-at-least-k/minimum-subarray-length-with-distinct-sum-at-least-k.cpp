class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int l=0;
        int ans=INT_MAX;
        int sm=0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end()) sm+=nums[i];
            mp[nums[i]]++;
            while(sm>=k){
                ans= min(ans,i-l+1);
                mp[nums[l]]--;
                if(mp[nums[l]]==0) {
                mp.erase(nums[l]);
                sm-=nums[l];
                }
                l++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};