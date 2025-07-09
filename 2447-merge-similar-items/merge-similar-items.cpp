class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int>mp;
        vector<vector<int>>ans;
        for(auto it:items1){
            mp[it[0]]+=it[1];
        }
        for(auto it:items2){
            mp[it[0]]+=it[1];
        }
        for(auto it:mp){
            ans.push_back({it.first,it.second});
        }
        return ans;
    }
};