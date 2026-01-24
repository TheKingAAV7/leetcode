class Solution {
public:
    int minPairSum(vector<int>& nums) {
       int n=nums.size();
       sort(nums.begin(),nums.end()); // never forget to sort..
       int ans=0;
       int i=0,j=n-1;
       while(i<=j){
        int pairsm= nums[i]+nums[j];
        ans=max(pairsm,ans);
        i++;
        j--;
       }
       return ans;

    }
};