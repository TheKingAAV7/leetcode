
#define ll long long
class Solution {
public:

    
    /*

    (x(x+1)) <= 2*t
    wt[i]*(x*(x+1)) <= 2*t


    */
    long long minNumberOfSeconds(ll mH, vector<int>& wt) {
        
        
        ll ans=-1;
        ll n=wt.size();

        auto findx=[&](ll weight,ll tim)->ll{
            ll tmp=-1;
            ll lo=0, hi=1e6;
            while(lo<=hi){
                ll mid=(lo+hi)>>1;
                if(weight*(mid+1)*mid<=2ll*tim){
                    tmp=mid;
                    lo=mid+1;
                }
                else hi=mid-1;
            }
            return tmp;
        };

        auto f=[&](ll k)->bool{
            ll th=mH;
            for(int i=0;i<n;i++){
                ll reqx=findx(wt[i],k);
                if(reqx==-1) return false;
                th-=reqx;
            }
            //  cout<<k<<" "<<th<<endl;
            return th<=0ll;
        };
        ll lo=1, hi= 1e18;
        while(lo<=hi){
            ll mid=(lo+hi)>>1;
            if(f(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;

    }
};