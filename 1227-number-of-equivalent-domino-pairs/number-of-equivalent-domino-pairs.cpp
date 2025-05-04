class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dom) {
        unordered_map<int,int>mp;
        int tmp=0;
        for(auto &it:dom){
            if(it[1]<it[0]) swap(it[0],it[1]);
            tmp= it[0]*10+it[1];
            mp[tmp]++;
        }
        int ans=0;
        for(auto [x,y]:mp){
            ans+=(y*(y-1))/2;
        }
        return ans;
    }
};