class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int sm=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                sm+=nums[i];
            }
            else{
                ans=max(ans,sm);
                sm=nums[i];
            }
        }
        ans=max(ans,sm);
        return ans;
    }
};