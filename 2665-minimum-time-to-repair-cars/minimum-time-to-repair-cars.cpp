#define ll long long
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(),ranks.end());
        ll lo=0,hi=1LL*ranks[0]*cars*cars;
        ll ans=hi;
        auto f=[&](ll m)->bool{
            ll cnt=0;
            ll tmp=m;
            for(auto it:ranks){
                tmp=m;
                tmp/=it;
                cnt+=(sqrt(tmp));
            }
            return cnt>=cars;
        };
        while(lo<=hi){
            ll mid=lo+(hi-lo)/2;
            if(f(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};