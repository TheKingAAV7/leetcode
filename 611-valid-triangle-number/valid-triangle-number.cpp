class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // 2 3 4 4
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sm=nums[i]+nums[j];
                auto it=lower_bound(nums.begin(),nums.end(),sm);
                int idx=it-nums.begin();
                    ans+=max(0,(idx-j-1));
            }
        }
        return ans;
    }
};