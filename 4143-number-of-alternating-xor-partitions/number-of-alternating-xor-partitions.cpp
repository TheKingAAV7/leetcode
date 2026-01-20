class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int n= nums.size();
        int MOD=1e9+7;
        map<long long,long long>dp1,dp2;
        int xo=0;
        dp1[0]=1;
        dp2[0]=1;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            xo^=nums[i];
            // start with target1
           // cout<<xo<<" ";
             long long req1= xo^target1;
             long long req2= xo^target2;

             long long nxt1= dp2[req1];
             long long nxt2= dp1[req2];
             dp1[xo]= (dp1[xo]+nxt1)%MOD;
            // start with targt2
           
            dp2[xo]= (dp2[xo] + nxt2)%MOD;

            //cout<<dp1[xo]<<endl;

            ans=nxt1;
        }
        //cout<<endl;
        long long req= xo^target1;
        
        return ans;
      //  return ans;
        
    }
};