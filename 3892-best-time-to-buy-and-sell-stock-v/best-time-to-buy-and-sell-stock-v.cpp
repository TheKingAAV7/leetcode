#define ll long long
/*
WE can optimize this by maintaining maximum and minimum values..


*/
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int K) {
        int n=prices.size();
        vector<vector<ll>>dp(n+1,vector<ll>(K+2,0));
        vector<vector<ll>>mx1(n+1,vector<ll>(K+2,-1e12));
        vector<vector<ll>>mx2(n+1,vector<ll>(K+2,-1e12));
        
        // mn mx
        for(int k=1;k<=K;k++){ 
        mx1[n-1][k]=prices.back();
        mx2[n-1][k]= -prices.back();
        }
        for(int i=n-2;i>=0;i--){
            for(int k=1;k<=K;k++){
                dp[i][k]=max(dp[i][k],dp[i+1][k]);
                ll mxi= mx1[i+1][k];
                ll mxj= mx2[i+1][k];
                dp[i][k]=max(dp[i][k],mxi-prices[i]);
                dp[i][k]=max(dp[i][k],mxj+prices[i]);
                mx1[i][k]= max({mx1[i][k],prices[i]+dp[i+1][k-1],mx1[i+1][k]});
                mx2[i][k]=max({mx2[i][k],dp[i+1][k-1]-prices[i],mx2[i+1][k]});
                // for(int j=i+1;j<n;j++){  // prices[i]+dp[j+1][k-1]-prices[j]   - prices[j]+dp[j+1][k-1] - prices[i]
                //     dp[i][k]= max(dp[i][k],abs(prices[j]-prices[i])+dp[j+1][k-1]);
                
                    
                // }
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++) {
            // for(int j=1;j<=K;j++) cout<<dp[i][j]<<" ";
            // cout<<endl;
            ans=max(ans,dp[i][K]);
        }
        // cout<<endl;
        return ans;
    }
};