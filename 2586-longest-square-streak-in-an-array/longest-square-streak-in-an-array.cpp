class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<long long,long long>mp;
        sort(nums.begin(),nums.end());
        for(int i:nums) mp[i]++;
        int ans=1;
        long long po;
        for(long long ele:nums){
            po=ele*ele*1ll;
            int cnt=1;
            while(mp.find(po)!=mp.end()){
                cnt++;
                po= po*po;
            }
            ans=max(ans, cnt);
        }
        return ans==1? -1:ans;
    }
};