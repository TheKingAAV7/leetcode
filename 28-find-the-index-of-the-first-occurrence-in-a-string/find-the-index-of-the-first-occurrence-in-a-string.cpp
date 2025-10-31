#define ll long long
class Solution {
public:
        ll mod=1e9+7;
        ll p=31;

    int strStr(string s, string pat) {
        ll n=s.length();
        ll m=pat.length();
        
        if(m>n) return -1; 
        vector<ll>po(n+1,0);
        po[0]=1;
        for(int i=1;i<n;i++){
            po[i]= (po[i-1]*p)%mod;
        }
        ll hshp=0;

        for(int i=0;i<m;i++){
            ll val = (po[i]*(pat[i]-'a'+1))%mod;
            hshp= (hshp + val)%mod;
        }
        vector<ll>hsh(n,0);

        hsh[0]= (s[0]- 'a' + 1) ;
        for(int i = 1 ; i < n ; i++){
            ll val= (po[i]* (s[i]-'a'+1))%mod;
            hsh[i]= ( hsh[i-1] + val)%mod;
        }
        // for(int i:po) cout<<i<<" ";
        // cout<<endl;
        // for(int i:hsh) cout<<i<<" ";
        // cout<<endl;
        // cout<<hshp<<endl;

        for(int i=0;i<n;i++){
            if(i==0){
                ll cur= hsh[i+m-1];
                if(cur==hshp) return 0;
            }
            else{
                if(i+m-1>=n) continue;
                ll rig= hsh[i+m-1];
                ll lef= hsh[i-1];
                ll sub_hash= (rig-lef+mod)%mod;
                if(sub_hash==((hshp*po[i])%mod)) return i;
            }
        }
        return -1;
        
        return -1;
        
    }
};