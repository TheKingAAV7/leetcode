class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        int l=0;
        int sm=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            while(st.find(nums[i])!=st.end()){
                sm-=nums[l];
                st.erase(nums[l]);
                l++;
            }
            st.insert(nums[i]);
            sm+=nums[i];
            maxi=max(maxi,sm);
        }
        return maxi;
    }
};