class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
         map<int,int>mp;
        vector<int>ans;
        for(int i:friends) mp[i]++;
        for(int i:order){
            if(mp.find(i)!=mp.end()) ans.push_back(i);
        }
        return ans;

    }
};