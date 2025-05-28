class Solution {
public: // 0 1 3 3 5 5
    int minimumOperations(vector<int>& nums) {
       set<int>st;
       for(int i:nums){
        if(i>0) st.insert(i);
       }
       return st.size();
    }
};