#define ll long long
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
       // 2 5 5 6 7
    
       int n=nums.size();
       sort(nums.begin(),nums.end());
       int med=n/2;
       ll ans=0;
       for(int i=med;i>=0;i--){
         if(nums[i]>k) ans+=(nums[i]-k);
      
       }
       for(int i=med;i<n;i++){
        if(nums[i]<k)  ans+=(k-nums[i]);
        
       }
       return ans;
    }
};