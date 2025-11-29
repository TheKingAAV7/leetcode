class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sm= accumulate(nums.begin(),nums.end(),0);
        return sm%k;
    }
};