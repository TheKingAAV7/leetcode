class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(K+1,vector<int>(n+1,0));
        vector<int>maxi(n,0);
        int tmp=0;
        for(int i=n-1;i>=0;i--){
            tmp=max(tmp,prices[i]);
            maxi[i]=tmp;
        }
        
        for(int k=1;k<=K;k++){
            int cur_maxi=0;
            for(int i=n-2;i>=0;i--){
                dp[k][i]=max({dp[k][i],dp[k][i+1],maxi[i+1]-prices[i]});
            }
            for(int i=n-1;i>=0;i--){
                cur_maxi=max(cur_maxi,dp[k][i]+prices[i]);
                maxi[i]=cur_maxi;
            }

        }
        // for(int i=0;i<=K;i++){
        //     for(int k=0;k<n;k++) cout<<dp[i][k]<<" ";
        //     cout<<endl;
        // }
        return dp[K][0];
    }
};