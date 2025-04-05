class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        for(int i:nums)
        ans|=i;

        int n=nums.size();
        return ans*pow(2,n-1);
    }
};