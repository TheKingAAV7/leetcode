class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xoro=0;
        int n=nums.size();
        for(int i=0;i<=n;i++) xoro^=i;
        for(int i: nums) xoro^=i;
        return xoro;
    }
};