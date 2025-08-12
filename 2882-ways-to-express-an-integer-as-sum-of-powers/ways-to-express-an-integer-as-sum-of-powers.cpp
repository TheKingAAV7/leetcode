class Solution {
public:
    
    int mod=1e9+7;
    int binpow(int base, int exp, int mod) {
    long long res = 1;
    long long b = base % mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res * b) % mod;
        b = (b * b) % mod;
        exp >>= 1;
    }
    return (int)res;
}

    int f(int n, int x, int i,int sm,vector<vector<int>>&dp){
        
        
        if(sm==n) {
        // cout<<"yes"<<endl;
        return 1;
        }
        if(sm>n || i>(n)) return 0;
      //  cout<<i<<" "<<sm<<endl;
        if(dp[i][sm]!=-1) return dp[i][sm];
        int ans=0;
        // ntake 
         ans = (ans+f(n,x,i+1,sm,dp))%mod;
        //take
       // cout<<sm+pow(i,x)<<endl;
         ans = (ans+f(n,x,i+1,sm+binpow(i,x,mod),dp))%mod;
         return dp[i][sm]=ans;
        
    }
    int numberOfWays(int n, int x) {
       vector<vector<int>>dp(302,vector<int>(302,-1));
       int ans=f(n,x,1,0,dp)%mod;
    //   if(x==1) ans= (ans+1)%mod;
       return ans;
    }
};