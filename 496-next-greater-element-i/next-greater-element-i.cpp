class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        stack<int>st;

        for(int i=0;i<nums2.size();i++){
            while(!st.empty() and nums2[i]>st.top()){
                mp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int &i:nums1){
         if(mp.find(i)!=mp.end())
         ans.push_back(mp[i]);
         else ans.push_back(-1);
        }
        return ans;
    }
};