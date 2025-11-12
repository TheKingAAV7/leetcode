class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n=nums.size();
        int gc=nums[0];
        for(int i=1;i<n;i++) gc=gcd(gc,nums[i]);
        return gc==1;
    }
};