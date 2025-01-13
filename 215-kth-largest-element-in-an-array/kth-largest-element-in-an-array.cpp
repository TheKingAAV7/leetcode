class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>> st;
        for(int i:nums)st.insert(i);
        auto it=st.begin();
        advance(it,k-1);
        return *it;
    }
};