class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& que) {
       int n=nums.size();
       set<int>st;
       vector<bool>ans;
       if(n==1){
        int m=que.size();
        ans.resize(m,true);
        return ans;
       }
       for(int i=0;i<n-1;i++){
        if(nums[i]%2 == nums[i+1]%2){
            st.insert(i);
        }
       }
       for(auto it:que){
            int l=it[0],r=it[1];
            if(l==r){
                ans.push_back(true);
                continue;
            }
            auto it1=st.lower_bound(l);
            if(it1==st.end()){
             ans.push_back(true);
             continue;
            }
            if(*it1<r){
                ans.push_back(false);
            }
            else ans.push_back(true);
       }
       return ans;
    }
};