class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(int i:nums) st.insert(i);
        int cur=k;
        while(st.find(cur)!=st.end()) cur+=k;
        return cur;
    }
};