#define ll long long
class Solution {
public:
ll M=1e9+7;

    ll binpow(ll a, ll b){
        if(b==0) return 1ll;
        ll half= binpow(a,b/2);
        half= (half*half)%M;
        if(b&1) half=(half*a)%M;
        return half%M;
    }

    
    int sumOfNumbers(int L, int R, int K) {
        ll sm=0;
        for(int i=L;i<=R;i++) sm+=i;
        ll l=L;
        ll r= R;
        ll k=K;
        ll base= r-l+1;
        ll p1= k-1;
        // cout<<base<<" "<<k-1<<endl;
        ll ans= (sm*binpow(base,k-1ll))%M ;
        // cout<<sm<<" "<<ans<<endl;
        ll last= binpow(10ll,k)%M;
        last=(last-1+M)%M;

        ll inv= binpow(9ll,M-2);
        last=(last*inv)%M;
        ans=(ans*last)%M;
        return ans;

        return ans;
    
    }
};