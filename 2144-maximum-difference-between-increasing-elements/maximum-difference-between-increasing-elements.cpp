class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int maxi=nums.back();
        for(int i=n-2;i>=0;i--){
            if(maxi>nums[i])
            ans=max(ans,(maxi-nums[i]));
           
            maxi=max(nums[i],maxi);
        }
        return ans==INT_MIN?-1:ans;
    }
};