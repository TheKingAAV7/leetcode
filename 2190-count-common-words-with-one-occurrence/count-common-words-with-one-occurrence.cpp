class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mp,mp1;
        for(auto it:words1) mp[it]++;
        for(auto it:words2) mp1[it]++;
        int ans=0;
        for(auto it:mp){
            if(it.second==1 and mp1.find(it.first)!=mp1.end() and mp1[it.first]==1) ans++;
        }
        return ans;
    }
};