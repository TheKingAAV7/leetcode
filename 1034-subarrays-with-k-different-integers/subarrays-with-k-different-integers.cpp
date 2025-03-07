class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int gk=0,gk1=0;
        map<int,int>mp,mp1;
        int l=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp.size()>=k){
                gk+=(n-i);
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
        }
        l=0;
        for(int i=0;i<n;i++){
            mp1[nums[i]]++;
            while(mp1.size()>=(k+1)){
                gk1+=(n-i);
                mp1[nums[l]]--;
                if(mp1[nums[l]]==0) mp1.erase(nums[l]);
                l++;
            }
        }
        return gk-gk1;
    }
};