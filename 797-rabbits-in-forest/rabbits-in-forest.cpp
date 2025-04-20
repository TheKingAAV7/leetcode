class Solution {
public:
    int numRabbits(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        int ans=0;
        for(int i:arr) mp[i]++;
        for(auto it:mp){
            double x=it.first;
            double cnt=ceil(it.second/(x+1.00));
            ans+=(ceil(cnt)*(x+1));
        }
        return ans;
    }
};