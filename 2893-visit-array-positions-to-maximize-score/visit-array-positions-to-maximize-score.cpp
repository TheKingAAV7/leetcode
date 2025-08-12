
#define ll long long
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
     //   dp[i][0]=max(dp[i+1][0],dp[i+1][1]-x)
     int n=nums.size();
     vector<vector<ll>>dp(n+1,vector<ll>(2,0));
     for(int i=n-1;i>=0;i--){
        if(nums[i]%2==0){
        dp[i][0]=max({0ll+nums[i]+dp[i+1][0],0ll+nums[i]+dp[i+1][1]-x,0ll});
        dp[i][1]=max(dp[i][1],dp[i+1][1]);
        }
        else{
         dp[i][1]=max({0ll+nums[i]+dp[i+1][1],0ll+nums[i]+dp[i+1][0]-x,0ll});
         dp[i][0]=max(dp[i][0],dp[i+1][0]);

        }
      //  cout<<"("<<dp[i][0]<<" "<<dp[i][1]<<")"<<endl;
     }

        if(nums[0]&1) return dp[0][1];
     return dp[0][0];
    }
};