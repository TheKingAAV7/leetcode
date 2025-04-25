class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans=0;
        int pref=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i:nums){
        if(i%modulo==k){
            pref++;
        } 
        int rem=pref%modulo;
        if(mp.find((rem-k+modulo)%modulo)!=mp.end()){
            ans+=mp[((rem-k+modulo)%modulo)];
        }
        mp[rem]++;
        }
        return ans;
    }
};