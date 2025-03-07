class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        int sm=0;
        int cnt=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            int req=sm-k;
            if(mp.find(req)!=mp.end()) cnt+=mp[req];
            mp[sm]++;
        }
        return cnt;
    }
};