class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[1]=1;
        dp[0]=1;
        for(int i=2;i<=n;i++){
            int sm=0;
            for(int j=1;j<=i;j++){
               sm+=(dp[j-1]*dp[i-j]);
            }
            dp[i]=sm;
        }
        return dp[n];
    }
};