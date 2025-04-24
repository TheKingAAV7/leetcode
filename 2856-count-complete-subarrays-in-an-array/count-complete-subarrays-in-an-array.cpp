class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i:nums) mp[i]++;
        int cnt=mp.size();
        int ans=0;
        mp.clear();
        int l=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp.size()==cnt){
                ans+=(n-i);
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
        }
        return ans;
    }
};