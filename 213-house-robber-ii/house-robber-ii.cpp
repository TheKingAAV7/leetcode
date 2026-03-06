class Solution {
public:
    int rob(vector<int>& nums) {
        //    1 2 3 1 1 2 3 1
        //    0 1 2 3 4 5 6 7
//                    0 1 2 3

  // 2 3 2 2 3 2

        int ans=0;
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp;
        function<int(int,int)>f=[&](int i, int sz)->int{
            if(i>=sz) return 0;
            if(dp[i]!=-1) return dp[i];
            int ans=0;
            ans=max(ans,f(i+1,sz));
            // int nxtidx= (())
            ans=max(ans,nums[i]+f(i+2,sz));
            return dp[i]=ans;
        };
        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        for(int i=0;i+n<2*n;i++){
            int l=i;
            int rig= l+n-1;
            dp.assign(2*n,-1);
            int cur=f(l,rig);
            // cout<<l<<" "<<cur<<endl;
            
            ans=max(ans,cur);
        }
        return ans;

    }
};