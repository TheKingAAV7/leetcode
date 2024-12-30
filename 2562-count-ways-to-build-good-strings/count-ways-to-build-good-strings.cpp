class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,0);
        int mod=1e9+7;
        int sum=0;
        dp[zero]+=1;
        dp[one]+=1;
        for(int i=1;i<=high;i++){
            if(zero<=i){
                dp[i]=(dp[i]+dp[i-zero])%mod;
            }
            if(i-one>=0){
                dp[i]=(dp[i]+dp[i-one])%mod;
            }
            if(i>=low and i<=high){
                sum=(sum+dp[i])%mod;
            }
        }
        return sum;
    }
};