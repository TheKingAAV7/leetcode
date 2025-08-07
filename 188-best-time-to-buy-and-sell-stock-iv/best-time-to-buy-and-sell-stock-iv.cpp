class Solution {
public:
    int maxProfit(int k, vector<int>& pr) {
        int n=pr.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int x=1;x<=k;x++){
                for(int j=i+1;j<n;j++){
                    if(pr[j]>pr[i]){
                        dp[i][x]=max(dp[i][x],(pr[j]-pr[i])+dp[j][x-1]);
                    }
                    dp[i][x]=max(dp[i+1][x],dp[i][x]);
                }
            }
        }
        return dp[0][k];
    }
};