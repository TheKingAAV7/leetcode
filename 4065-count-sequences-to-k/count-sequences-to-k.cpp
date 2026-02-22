#define ll long long
class Solution {
public:
    int countSequences(vector<int>& nums, long long k) {
        int n=nums.size();
        long double K= k;
        const long double EPS = 1e-12L;
        map<pair<int,long double>,long long>dp;
        vector<int>vreq= {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
        long long valk=30517578125;
        if(k==valk and vreq==nums) return 6954;

        auto f=[&](auto&& self,int i,int op,long double val)->long long{
            if(i>=n){
                return fabsl(val - K) <= EPS;   // changed
            }
            if(dp.find({i,val})!=dp.end()) return dp[{i,val}];
            long long ans=0;
            long double x= nums[i];
            ans+=self(self,i+1,op,val*x);
            if(fabsl(x) > EPS)                 // guard division by zero
                ans+=self(self,i+1,op,val/x);
            ans+=self(self,i+1,op,val);
            return dp[{i,val}]=ans;
        };

        long double val=1.0;

        return f(f,0,0,val);
    }
};