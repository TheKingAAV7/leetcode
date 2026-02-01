class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffmin(n,INT_MAX);
        int mn=INT_MAX;
        for(int i=n-1;i>=0;i--){
            suffmin[i]=mn;
            mn=min(mn,nums[i]);
        }
        int ans=INT_MAX;
        for(int i=1;i<n-1;i++){
            ans= min(ans,nums[0]+nums[i]+suffmin[i]);
        }
        return ans;
    }
};