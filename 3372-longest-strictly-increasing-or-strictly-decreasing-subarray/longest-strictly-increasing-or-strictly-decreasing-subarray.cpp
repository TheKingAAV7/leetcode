class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                cnt++;
            }
            else {
            ans=max(ans,cnt);
            cnt=1;
            }
        }
        ans=max(ans,cnt);
        cnt=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                cnt++;
            }
            else {
            ans=max(ans,cnt);
            cnt=1;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};