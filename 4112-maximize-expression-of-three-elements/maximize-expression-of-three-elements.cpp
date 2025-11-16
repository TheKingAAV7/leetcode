class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
       int ans1= nums[n-1]+nums[n-2] - nums[0];
       // last last first
       // first second last ?
       return ans1;

    }
};