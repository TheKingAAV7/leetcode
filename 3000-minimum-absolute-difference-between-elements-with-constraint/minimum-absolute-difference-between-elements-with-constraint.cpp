class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int>st;
        int n=nums.size();
        int ans=INT_MAX;
        int pos=n-1;
        for(int i=n-x-1;i>=0;i--){
            st.insert(nums[pos]);
            pos--;
            auto it=st.lower_bound(nums[i]);
            if(it==st.end()){
                it--;
                ans=min(ans,abs(*it-nums[i]));
            }
            else if(it==st.begin()){
                ans=min(ans,abs(*it-nums[i]));
            }
            else{
                ans=min(ans,abs(*it-nums[i]));
                it--;
                ans=min(ans,abs(*it-nums[i]));
            }

        }
        return ans;
    }
};