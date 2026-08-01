class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n= nums.size();
        int dp[20][20][2];
        fill(&dp[0][0][0], &dp[0][0][0] + 20*20*2, -1);
        auto f=[&](auto &&self,int lf, int rg, int turn)->int{
            if(lf>rg) return 0;
            if(dp[lf][rg][turn]!=-1) return dp[lf][rg][turn];
            int diff=0;
            int ans1,ans2;
            if(!turn) {
                ans1=nums[lf]+self(self,lf+1,rg,!turn);
                ans2=nums[rg]+self(self,lf,rg-1,!turn);
                return dp[lf][rg][turn]= max(ans1,ans2);
            }
            else{
                ans1= -nums[lf] + self(self,lf+1,rg,!turn);
                ans2= -nums[rg] + self(self,lf,rg-1,!turn);
                return dp[lf][rg][turn]=min(ans1,ans2);
            }
            return 0;

        };
        int ans= f(f,0,n-1,0);
       
        return ans>=0;
    }
};