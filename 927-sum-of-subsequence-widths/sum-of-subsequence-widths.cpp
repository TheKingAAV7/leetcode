class Solution {

private:
int mod=1e9+7;
long long powmod(int a, int b){
    if(b==0) return 1ll;
    long long tmp= powmod(a,b/2);
    long long stmp=(tmp%mod*tmp%mod)%mod;
    if(b%2==0) return stmp;
    return (stmp%mod*a%mod)%mod;
}
public:
    int sumSubseqWidths(vector<int>& nums) {
        /* 
         1 2 3 4 
         3-> 2^0 * 1  = 1
         2-> 2^1 * 2  +  2^0 * 1 = 5
         1-> 2^2*3 + 2^1*2 + 2^0*1 = 12+4+1 
        */
        int n=nums.size();
        if(n==1) return 0;
        long long ans=0;
        sort(nums.begin(),nums.end());
        int cnt=2;
        vector<long long>dp(n,0);
        dp[n-2]= nums[n-1]-nums[n-2];
        for(int i=n-3;i>=0;i--){
            long long diff=(nums[i+1]-nums[i]);
            dp[i] = (2*dp[i+1])%mod;
            long long tmp= powmod(2,cnt) -1;
            cnt++;
            long long stmp= (tmp%mod * diff%mod)%mod;
       //     cout<<stmp<<endl;
            dp[i]= (dp[i]%mod + stmp%mod)%mod;
        }
        for(long long i:dp) {
           // cout<<i<<" ";
            ans= (ans%mod+i%mod)%mod;
        }
        
        return (int)(ans);
    }
};