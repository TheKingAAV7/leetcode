class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n,0);
        int ans=0;
        for(int i=n-2;i>=0;i--){
            dp[i]=max((prices[i+1]-prices[i])+dp[i+1],dp[i]);
            dp[i]=max(dp[i],dp[i+1]);
        }
        
        return dp[0];
    }
};