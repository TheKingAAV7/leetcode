class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=k-1;
        int j=0;
        int ans=INT_MAX;
        while(i<n){
            ans=min(ans,nums[i]-nums[j]);
            i++;j++;
        }
        return ans;
    }
};