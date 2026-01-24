class Solution {
public:
    int minPairSum(vector<int>& nums) {
       int n=nums.size();
       sort(nums.begin(),nums.end()); // never forget to sort.. nlogn
       int ans=0;
    
       for(int i=0;i<n/2;i++){
        int pairsm= nums[i] + nums[n-i-1];
        ans=max(ans,pairsm);
       }
       return ans;

    }
};