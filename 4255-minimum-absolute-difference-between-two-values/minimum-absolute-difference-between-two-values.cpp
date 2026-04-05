class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i]==1 and nums[j]==2) ans= min(ans,abs(i-j));
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};