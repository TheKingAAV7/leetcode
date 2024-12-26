class Solution {
private:
int f(int i, int n,vector<int>&nums,int target,int ans){
    if(i==n-1){
        int one=ans+nums[i];
        int two=ans-nums[i];
        return (one==target) + (two==target);
    }

    int plus= f(i+1,n,nums,target,ans+nums[i]);
    int minus=f(i+1,n,nums,target,ans-nums[i]);
    return plus+minus;
}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        int n=nums.size();
        int res=f(0,n,nums,target,ans);
        return res;
    }
};