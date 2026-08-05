class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=nums[0];
        int r=nums.back();
        vector<int>ans;
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=l+1;i<r;i++){
            if(st.find(i)==st.end()) ans.push_back(i);
        }
        return ans;
    }
};