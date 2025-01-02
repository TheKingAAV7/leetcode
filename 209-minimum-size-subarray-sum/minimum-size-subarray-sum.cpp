class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sm=0;
        int n=nums.size();
        int l=0;
        int ans=n+1;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            while(sm>=target){
                 ans=min(ans,i-l+1);
                sm-=nums[l++];

            }
           
        }
        if(ans==n+1) return 0;
        return ans;
    }
};