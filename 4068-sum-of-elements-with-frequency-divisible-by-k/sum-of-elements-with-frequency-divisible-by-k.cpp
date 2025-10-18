class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int ans=0;
        for(int i:nums) mp[i]++;
        for(auto it:mp){
            if(it.second%k==0) ans+= it.first*it.second;
        }
        return ans;
    }
};