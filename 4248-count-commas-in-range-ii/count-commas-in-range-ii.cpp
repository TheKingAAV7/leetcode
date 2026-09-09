#define ll long long
class Solution {
public:
    /*

   000000000
    596000

    1-999
    1000-999999
    1
    [1-3] -> 0
    [4,6] -> 1
    [7,9] -> 2
    [10,12]
    [13-15]
    


    */
    long long countCommas(long long n) {
        
       vector<array<ll,3>> v = {
            {1LL,                 999LL,                   0LL},
            {1000LL,              999999LL,                1LL},
            {1000000LL,           999999999LL,             2LL},
            {1000000000LL,        999999999999LL,          3LL},   
            {1000000000000LL,     999999999999999LL,       4LL},
            {1000000000000000LL,  999999999999999999LL,    5LL}
        };
        int sz=v.size();
        ll ans=0;
        for(auto it:v){
            ll lo= it[0];
            ll hi= it[1];
            ll cnt= it[2];
            if(hi<=n){
                ans+=(1ll*cnt*(hi-lo+1ll));
            }
            else{
                ans+=(1ll*cnt*(n-lo+1ll));
                break;
            }
            
        }
        return ans;
        
    }
};