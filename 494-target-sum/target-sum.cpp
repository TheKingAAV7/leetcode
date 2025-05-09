class Solution {
private:
map<int,map<int,int>>dp;
int f(int i, int n,vector<int>&nums,int target,int ans){
    if(i==n-1){
        int one=ans+nums[i];
        int two=ans-nums[i];
        return (one==target) + (two==target);
    }
    if(dp.find(i)!=dp.end() and dp[i].find(ans)!=dp[i].end()){
        return dp[i][ans];
    }

    int plus= f(i+1,n,nums,target,ans+nums[i]);
    int minus=f(i+1,n,nums,target,ans-nums[i]);
    return dp[i][ans]=plus+minus;
}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        int n=nums.size();
      
     
        int res=f(0,n,nums,target,ans);
        
        return res;
    }
};