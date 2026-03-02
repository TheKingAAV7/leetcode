class Solution {
public:
#define ll long long
/*

    can we solve it using dijkstra, by flippint the 
*/
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int MOD=1e9+7;
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<ll>>dp(max(n,m),vector<ll>(2,-1));
        function<ll(int,int)>f=[&](int i, int par)->ll{
            if(par==0){
                if(i>=n) return 0;
            }
            if(par==1 and i>=m) return 0;
            if(dp[i][par]!=-1) return dp[i][par];
            ll ans=0;
            // continue on the same par
            
            ans= max(ans,(par==0?nums1[i]:nums2[i]) + f(i+1,par));
            // shift to other
            auto it=nums1.begin();
            if(par==0){
                it= lower_bound(nums2.begin(),nums2.end(),nums1[i]);
                if(it!=nums2.end() and *it==nums1[i]){
                    int idx= it-nums2.begin();
                    ans= max(ans,nums1[i]+ f(idx+1,1));
                }
            }
            else{
                it= lower_bound(nums1.begin(),nums1.end(),nums2[i]);
                if(it!=nums1.end() and *it==nums2[i]){
                    int idx= it-nums1.begin();
                    ans= max(ans,nums2[i]+ f(idx+1,0));
                }
            }
            return  dp[i][par]=ans;
            
        };
        return max(f(0,0),f(0,1))%MOD;
    }
};