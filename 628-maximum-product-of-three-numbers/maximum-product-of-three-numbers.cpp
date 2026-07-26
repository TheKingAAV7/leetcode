class Solution {
public:
    int maximumProduct(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int n= nums.size();
      if(nums.back()<=0){
        return nums.back()*nums[n-2]*nums[n-3];
      } 
      return max(nums.back()*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums.back());
    }
};