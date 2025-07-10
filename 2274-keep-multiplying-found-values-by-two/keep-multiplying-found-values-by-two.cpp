class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        multiset<int>st;
        for(int i:nums) st.insert(i);
        while(st.find(o)!=st.end()){
            auto it=st.find(o);
            st.erase(it);
            o*=2;
        }
        return o;
    }
};