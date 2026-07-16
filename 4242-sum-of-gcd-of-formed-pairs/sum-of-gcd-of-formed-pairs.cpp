#define ll long long
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<ll>pref(n,0);
        ll mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,1ll*nums[i]);
            pref[i]=gcd(nums[i],mx);
        }
        sort(pref.begin(),pref.end());
        int i=0,j=n-1;
        ll sm=0;
        while(i<j){
            sm+= gcd(pref[i],pref[j]);
            i++;
            j--;
        }
        return sm;
    }
};