class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        long long n=nums.size();
        unordered_map<int,long long>mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]-i)!=mp.end()){
                ans+=mp[nums[i]-i];
            }
            mp[nums[i]-i]++;

        }
        long long tmp=n*(n-1)/2;
        return tmp-ans;
    }
};