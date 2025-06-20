class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n,0);
        int maxi=prices.back();
        for(int i=n-2;i>=0;i--){
            maxi=max(maxi,prices[i]);
            dp[i]=max({dp[i+1],maxi-prices[i],dp[i]});
        }
        int mini=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            mini=min(mini,prices[i]);
            ans=max(ans,(prices[i]-mini)+dp[i]);
        }
        return ans;
    }
};