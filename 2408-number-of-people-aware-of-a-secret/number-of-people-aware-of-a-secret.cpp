#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        /*
          1-> (2,3)-> (4,5) (5,6)
              (3,4)


        */
        vector<int>dp(n+1,0);
        int child=forget-delay;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            // this ith state can be reached through i-delay
            // we will just ignore forget for now..

            for(int j=0;j<child;j++){
                int prev= i-delay-j;
                //cout<<i<<" "<<prev<<endl;
                if(prev>=1){
                   dp[i]=(dp[i]+dp[prev])%mod;
                }

            }
            // if(i-delay>=1){
            //     dp[i]=(dp[i]+dp[i-delay])%mod;

            // }
        }
        // for(int i:dp) cout<<i<<" ";
        // cout<<endl;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i+forget>n) ans=(ans+dp[i])%mod;
        }
        return ans;

    }
};