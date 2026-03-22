class Solution {
public:

/*

dp[i][tar] = dp[i-1][tar]+1
             dp[i-1][tar^]


*/
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        const int a=41;
        const int b=1e5;
        int dp[a][b];
        memset(dp,-1,sizeof(dp));
        auto f=[&](auto &&self, int i,int tar)->int{
            if(i>=n){
                if(tar==0) return 0;
                return INT_MAX;
            }
            if(dp[i][tar]!=-1) return dp[i][tar];
            int take= self(self,i+1,tar^nums[i]);
            int ntake=self(self,i+1,tar);
            if(ntake!=INT_MAX) ntake++;
            return dp[i][tar]=min(take,ntake);
        };
        int ans= f(f,0,target);
        
        return ans==INT_MAX?-1:ans;
    }
};