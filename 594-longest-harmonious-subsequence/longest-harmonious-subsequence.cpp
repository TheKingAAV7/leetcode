class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            auto it=upper_bound(nums.begin(),nums.end(),nums[i]+1);
            if(it!=nums.begin()) it--;
            if(*it==nums[i]+1) {
                int j=it-nums.begin();
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};