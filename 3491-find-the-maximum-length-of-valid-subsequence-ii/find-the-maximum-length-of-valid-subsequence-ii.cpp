class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int x=0;x<k;x++){
            vector<int>dp(k,0);
            int maxi=0;
            for(int i=n-1;i>=0;i--){
                int cur=nums[i]%k;
                int req=(x-cur+k)%k;
                dp[cur]=max(dp[cur],1+dp[req]);
                maxi=max(maxi,dp[cur]);
            }
            ans=max(ans,maxi);
        }
        return ans;
    }
};