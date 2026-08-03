
#define ll long long
class Solution {
public:
    long long minInitialStrength(vector<int>& arr, vector<vector<int>>& b) {
        int n= arr.size();
        vector<ll>mp(n+1,0);
        for(auto &it:b){
          int l= it[0];
          int r= it[1];
          ll v= it[2];
          mp[l]+=v;
          mp[r+1]-=v;
        }
        for(int i=1;i<n;i++){
            mp[i]+= mp[i-1];
        }
        

        ll lo= 0;
        ll hi= LLONG_MAX;
        ll ans=-1;
        auto f=[&](ll mid)->bool{
            ll sub=0;
            ll cur= mid;
            for(int i=0;i<n;i++){
                ll ab= mp[i];
                if((cur+ab)>=arr[i]){
                    cur= max(0ll,(cur-arr[i]));
                }
                else return false;
            }
            return true;
        };
        while(lo<=hi){
            ll mid= (lo+hi)>>1;
            if(f(mid)){
                ans= mid;
                hi= mid -1;
            }
            else lo= mid+1;
        }
        return ans;
    }
};