class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        auto it1=lower_bound(nums.begin(),nums.end(),0);
        if(it1==nums.end()) return nums.size();
        int neg=(it1-nums.begin());
        auto it2=upper_bound(nums.begin(),nums.end(),0);
        int pos=(n-(it2-nums.begin()));
       
        return max(neg,pos);
    }
};