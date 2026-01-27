class Solution {
public:
    int maximumPopulation(vector<vector<int>>& events) {
        int n=events.size();
        map<int,int>mp;
        for(auto it:events){
            mp[it[0]]++;
            mp[it[1]]--;
        }
        int maxi=INT_MIN;
        int ans=-1;
        int sm=0;
        for(auto it:mp){
            sm+=it.second;
            if(sm>maxi){
                ans=it.first;
                maxi=sm;
            }
        }
        return ans;
    }
};