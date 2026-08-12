class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n= nums.size();
        int lef=0;

        map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp[nums[i]]>k){
                mp[nums[lef]]--;
                lef++;
            }
            ans=max(ans,i-lef+1);
        }
        return ans;
    }
};