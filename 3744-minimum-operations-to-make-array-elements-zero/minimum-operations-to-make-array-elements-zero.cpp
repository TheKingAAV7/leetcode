#define ll long long 
class Solution {
public:
    long long minOperations(vector<vector<int>>& q) {
        ll ans=0;
      for(auto it:q){
        ll lef=it[0],rig=it[1];
        ll sm=0,p=1;
        for(ll p4=1;p4<=rig;p4*=4){
            ll pl=max(lef,p4);
            ll pr=min(rig,p4*4-1);
            sm+=max(0LL,p*(pr-pl+1));
            p++;
        }
        ans+=(sm+1)/2;
      }
      return ans;
    }
};