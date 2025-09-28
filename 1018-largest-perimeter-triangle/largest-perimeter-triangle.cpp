class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // 1 1 2 10
        for(int i=n-1;i>1;i--){
            if(nums[i]<nums[i-1]+nums[i-2]){
                return nums[i]+nums[i-1]+nums[i-2];
            }
        }
        return 0;
    }
};