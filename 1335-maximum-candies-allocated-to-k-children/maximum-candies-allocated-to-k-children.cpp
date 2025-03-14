class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int ans=0;
        long long  lo=1,hi=accumulate(candies.begin(),candies.end(),0ll);
        auto f=[&](long long p)->bool{
            long long cnt=0;
            for(long long i:candies){
                cnt+=(i/p);
            }
          //  if(p==1) cout<<cnt<<endl;
            return cnt>=k;
        };
        while(lo<=hi){
            long long mid=(lo+hi)>>1;
            if(f(mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};