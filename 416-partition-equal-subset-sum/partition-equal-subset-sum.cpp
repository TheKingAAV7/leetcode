class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sm=accumulate(nums.begin(),nums.end(),0);
        if(sm%2) return false;
        int req=sm/2;
        
        vector<vector<int>>dp(n,vector<int>(req+1,0));
        if(nums[n-1]<=req){
            dp[n-1][nums[n-1]]=1;
        }
       
        for(int i=0;i<n;i++) dp[i][0]=1;
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=req;j++){
                dp[i][j]|=dp[i+1][j];
                if(j-nums[i]>=0){
                    dp[i][j]|=dp[i+1][j-nums[i]];
                }
            }
        }
        return dp[0][req];
    }
   
};