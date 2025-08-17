class Solution {
public:
    double new21Game(int n, int k, int maxp) {
        // copied.. was a tough one
        if(k==0 || n>=k+maxp) return 1.0;
        vector<double>dp(n+1);
        dp[0]=1.0;
        double wsm=1.0,res=0.0;
        for(int i=1;i<=n;i++){
            dp[i]=wsm/maxp;
            if(i<k) wsm+=dp[i];else res+=dp[i];
            if(i-maxp>=0) wsm-=dp[i-maxp];
        }
        return res;
    }
};