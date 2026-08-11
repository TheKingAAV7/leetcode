class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int n= nums.size();
        int sm=0;
        int cur= nums[0];
        sm=cur;
        set<int>st(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1) sm+=nums[i];
            else break;
        }
        while(st.count(sm)) sm++;
        return sm;
    }
};