
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int lo= -target;
        int hi= target;
        int n= nums.size();
        vector<int>dp(n,-1);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
            int diff= (nums[j]-nums[i]);
            if(lo<=diff and diff<=hi){
                if(dp[j]!=-1)
                dp[i]= max(1+dp[j],dp[i]);
            }

            }
        }
        // for(int i:dp) cout<<i<<" ";
        // cout<<endl;
        return dp[0];
    }
};