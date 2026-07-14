class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n= nums.size();
        int MOD=1e9+7;
        int mx= *max_element(nums.begin(),nums.end());
        int dp[200][202][202];
        fill(&dp[0][0][0] , &dp[0][0][0]+(200*202*202),-1);
        auto f=[&](auto &&self, int i, int g1, int g2)->int{
            if(i>=n){
                if(g1!=-1 and g2!=-1) return g1==g2;
                return 0;
            }      
            if(dp[i][g1+1][g2+1]!=-1) return dp[i][g1+1][g2+1];
            int ans=0;      
            // take in 1
            int ngc1= ((g1==-1)?nums[i]:gcd(g1,nums[i]));
            ans=(ans+self(self,i+1,ngc1,g2))%MOD;
            // take in 2
            int ngc2= ((g2==-1)?nums[i]:gcd(g2,nums[i]));
            ans=(ans+self(self,i+1,g1,ngc2))%MOD;

            ans=(ans+self(self,i+1,g1,g2))%MOD;

            return dp[i][g1+1][g2+1]=ans;
            
        };

        return f(f,0,-1,-1);
    }
};