class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 1 2 1 1 2 1
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        stack<array<int,2>>st;
        for(int i=0;i<2*n;i++){
            while(!st.empty() and nums[i]>st.top()[0]){
                if(st.top()[1]<n) ans[st.top()[1]]=nums[i];
                st.pop();
            }
            st.push({nums[i],i});
        }
        return ans;
    }
};