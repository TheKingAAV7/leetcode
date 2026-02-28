class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int &i:nums) mp[i]++;
        for(auto &it:mp){
            for(auto &it1:mp){
                if(it.first!=it1.first){
                    if(it1.second!=it.second) return {it.first,it1.first};
                }
            }
        }
        return {-1,-1};
    }
};