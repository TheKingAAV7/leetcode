class Solution {
using ll = long long;
public:
        ll dp[16][2][2][3][270][2];

        // od+ ,ev-
        //16,2,2,16,135,2
    ll f(int idx, int leading_zero,int tight,int cnt, int sm,int par,string &num){
        if(idx==(num.length())){
            return cnt>=2 and sm==0; 
        }
        
        if(dp[idx][leading_zero][tight][min(cnt,2)][sm+135][par]!=-1) return dp[idx][leading_zero][tight][min(cnt,2)][sm+135][par];
        int mx= tight?(num[idx]-'0') : 9;
        ll ans=0;
        
        for(int i=0;i<=mx;i++){
            bool iszero= (i==0);
            bool lzero=leading_zero && iszero;
            if(par){
                ans+=f(idx+1,lzero,tight && i==mx,cnt+(!lzero),sm+i,!par,num); // note
            }
            else  ans+=f(idx+1,lzero,tight && i==mx,cnt+(!lzero),sm-i,!par,num);
        }
        return  dp[idx][leading_zero][tight][min(cnt,2)][sm+135][par] = ans;
    }
    ll caller(ll num){
        memset(dp,-1,sizeof(dp));
        string s= to_string(num);
        
        int n=s.length();
        // index, leading_zero,tight,cnt,sm,parity(0 for odd)
        ll ans= f(0,true,true,0,0,0,s);
        return ans;
    }
    long long countBalanced(long long low, long long high) {
        


        return caller(high) - caller(low-1);
    }
};