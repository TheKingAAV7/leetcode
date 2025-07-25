class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st;
        int sm=0;
        for(int i:nums){
            if(i>0) st.insert(i);
        }
        for(int i:st) sm+=i;
        if(sm==0) return *max_element(nums.begin(),nums.end());
        return sm;
    }
};