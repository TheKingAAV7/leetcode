
#define ll long long
class Solution {
public://2 3 7
    long long countSubarrays(vector<int>& nums, long long k) {
        ll ans=0;
        int n=nums.size();
        vector<ll>pref(n,0);
        ll sm=0;
        for(int i=0;i<n;i++){
         sm+=nums[i];
         pref[i]=sm;
        }
        auto f=[&](int mid,int i)->bool{
           
            ll sm=pref[mid]-pref[i]+nums[i];
            ll tsm=(sm*(mid-i+1));
             
            if(tsm<k) return true;
            return false;
        };
        for(int i=0;i<n;i++){
            ll tmp=-1;
            int lo=i,hi=n-1;
            while(lo<=hi){
                int mid=(lo+hi)>>1;
                if(f(mid,i)){
                    tmp=mid;
                    lo=mid+1;
                }
                else hi=mid-1;
            }
            if(tmp!=-1) ans+=(tmp-i+1);
         //   cout<<i<<" "<<tmp<<endl;
        }
        return ans;
    }
};