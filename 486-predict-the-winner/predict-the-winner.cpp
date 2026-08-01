class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n= nums.size();

        auto f=[&](auto &&self,int lf, int rg, int turn)->int{
            if(lf>rg) return 0;
            int diff=0;
            int ans1,ans2;
            if(!turn) {
                ans1=nums[lf]+self(self,lf+1,rg,!turn);
                ans2=nums[rg]+self(self,lf,rg-1,!turn);
                return max(ans1,ans2);
            }
            else{
                ans1= -nums[lf] + self(self,lf+1,rg,!turn);
                ans2= -nums[rg] + self(self,lf,rg-1,!turn);
                return min(ans1,ans2);
            }
            return 0;

        };
        int ans= f(f,0,n-1,0);
        cout<<ans<<endl;
        return ans>=0;
    }
};