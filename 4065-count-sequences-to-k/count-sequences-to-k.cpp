
#define ll __int128
class Solution {
public:

    static __int128 abs128(__int128 x){ return x < 0 ? -x : x; }
    static __int128 gcd128(__int128 a, __int128 b){
    a = abs128(a); b = abs128(b);
    while (b != 0){
        __int128 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

    int countSequences(vector<int>& nums, long long k) {
        int n= nums.size();
        int lef= n/2;
        map<pair<ll,ll >,int>mp;
        
        int ans=0;

        auto f= [&](auto &&self, int i, int sz, int toggle, ll n1, ll d1 ){
            if(i>=sz){
                if(toggle==0){
               
                ll gc= gcd128(n1,d1);
                n1/=gc;
                d1/=gc;
                mp[{n1,d1}]++;
                return;
                }
                else{
                    
                   ll reqnum= d1*k;
                   ll reqden= n1;
                   ll gc= gcd128(reqnum,reqden);
                   reqnum/=gc;
                   reqden/=gc;
                   ans+=mp[{reqnum,reqden}];
                   
                }
                return; 
            }
            self(self,i+1,sz,toggle,n1*nums[i],d1);
            self(self,i+1,sz,toggle,n1,d1*nums[i]);
            self(self,i+1,sz,toggle,n1,d1);
            return ;
        };



        ll n1,d1;
        n1=d1=1;
        f(f,0,lef,0,n1,d1);
        // cout<<endl;
        //val=1;
        f(f,lef,n,1,n1,d1);
        
        return ans;
        
    }
};