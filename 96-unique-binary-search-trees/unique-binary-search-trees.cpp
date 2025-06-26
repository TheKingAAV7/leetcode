class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int sm=0;
            for(int j=1;j<=i;j++){
                int lef=(j-1);
                int rig=(i-j);
                if(lef==0) sm+=dp[rig];
                else if(rig==0) sm+=dp[lef];
                else{
                    sm+=(dp[lef]*dp[rig]);
                }
            }
            dp[i]=sm;
        }
        return dp[n];
    }
};