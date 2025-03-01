class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]&1) nums[i]=1;
            else nums[i]=0;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};