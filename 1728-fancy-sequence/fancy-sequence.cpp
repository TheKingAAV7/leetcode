const int MAXN=1e5+1;
#define ll long long
class Fancy {
public:
/*

  + ... -
  
  i dont know which operation is being performed
  if it's a lazy segtree , am giving up.

  How to handle multiplication 


*/
ll MOD=1e9+7;

   int n;
   vector<ll>v;
   ll add, mul;
    Fancy() {
        n=0;
        add=0;
        mul=1;
    }
    
    ll binpow(ll a, ll b){
        if(b==0) return 1ll;
        int ans= binpow(a,b/2ll);
        ans=(ans%MOD*ans%MOD)%MOD;
        if(b&1) ans=(ans*a)%MOD;
        return ans%MOD;
    }
    void append(int val) {
        n++;
        ll nval= (val-add+MOD)%MOD;
        ll tmp= binpow(mul,MOD-2);
        nval=(nval*tmp)%MOD;
        v.push_back(nval);

    }
    
    void addAll(int inc) {
        add=(add+inc)%MOD;
    }
    
    void multAll(int m) {
        mul=(mul*m)%MOD;
        add=(add*m)%MOD;
    }
    
    int getIndex(int idx) {
        if(idx<n){
            ll ans= (v[idx]*mul)%MOD;
            ans=(ans+add)%MOD;
            return ans;
        }
        return -1;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */