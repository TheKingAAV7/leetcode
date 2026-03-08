#define ll long long
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        vector<ll>p(n+1);
        p[n]=1ll;
        ll LIM= 1e15;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>LIM/p[i+1]){
                p[i]= LIM;
            }
            else p[i]= nums[i]*p[i+1];
        }
        ll totalsm=0;
        for(int i=0;i<n;i++){
            int sm= totalsm;
            int prod= p[i+1];
            if(sm==prod) return i;
            totalsm+=nums[i];
        }
        return -1;
    }
};