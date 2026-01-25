class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans=INT_MAX; //1e10
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i+k-1<n;i++){
            int current_difference= nums[i+k-1]- nums[i];
            ans=min(ans,current_difference);
        }
        return ans;
        
    }
};