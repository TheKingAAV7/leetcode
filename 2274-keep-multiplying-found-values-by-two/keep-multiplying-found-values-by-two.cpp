class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st(nums.begin(),nums.end());
        int cur= original ;
        while(st.find(cur)!=st.end()) cur*=2;

        return cur;
    }
};