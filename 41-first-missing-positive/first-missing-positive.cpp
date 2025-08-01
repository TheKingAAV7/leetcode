class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int x=1;
        unordered_map<int,int>mp;
        for(int i:nums) mp[i]++;
        while(mp.find(x)!=mp.end()){
            x++;
        }
        return x;
    }
};