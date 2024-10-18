class Solution {
private: 
int f(int i, int n, vector<int>&nums,int maxi, int curor ){
    if(curor==maxi){
         return 1<<(nums.size()-i);
    } 
    if(i>=n) return 0;
    int tmp= curor | nums[i];
    int take=f(i+1,n,nums,maxi,tmp);
    int ntake=f(i+1, n, nums, maxi, curor);
    return take+ntake;
}
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        for(int i: nums){
            maxi |= i;
        }
         
         return f(0, nums.size(),nums , maxi, 0);
    }
};