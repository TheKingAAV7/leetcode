class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        int g=n/k;
        map<int,int>mp;
        for(int i:nums){
            mp[i]++;
            if(mp[i]>g) return false;
        }
        return true;
    }
};