class Solution {
public:
    long long MOD=1e9+7;

    long long binpow(long long  a, long long b){
        if(b==0) return 1;
        long long half= binpow(a, b/2);
        half= (half%MOD*half%MOD)%MOD;
        if(b&1) half=(half%MOD*a%MOD)%MOD;
        return half;
    }
    int countGoodNumbers(long long n) {
        //  5 4 5 4
        long long odcnt= n/2ll;
        long long evcnt= n-odcnt;

        return (binpow(5ll,evcnt) * binpow(4ll,odcnt))%MOD;
    }
};