class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int lo= *min_element(nums.begin(),nums.end());
        int hi= *max_element(nums.begin(),nums.end());
        int ans=-1;
        auto f=[&](int x)->int{
            vector<int>dp(n+3,0);
            for(int i=n-1;i>=0;i--){
                dp[i]=max(dp[i],dp[i+1]);
                dp[i]= max(dp[i], (int)(nums[i]<=x) + dp[i+2]  );
            }
          
          
            return dp[0]>=k;
        };
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(f(mid)){
                ans= mid;
                hi=mid-1;
            }
            else lo= mid+1;
        }
        return ans;
    }
};