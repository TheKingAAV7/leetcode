class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,0);
        int mod=1e9+7;
        int share=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            if((i-delay)>=0)
            share= (share%mod+dp[i-delay]%mod)%mod;
            if((i-forget)>=0)  share = (share - dp[i - forget] + mod) % mod;
            dp[i]=share;
        }
        int res=0;
        for(int i=n-forget+1;i<=n;i++){
            res=(res%mod+dp[i]%mod)%mod;
        }

        return res;
    }
};