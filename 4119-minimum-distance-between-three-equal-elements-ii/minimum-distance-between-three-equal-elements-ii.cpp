class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);

        int ans=INT_MAX;
        for(auto it: mp){
            auto &cur= it.second;
            for(int i=1;i<cur.size()-1;i++){
                ans= min(ans,abs(cur[i-1]-cur[i])+abs(cur[i]-cur[i+1])+abs(cur[i-1]-cur[i+1]));
            }
        }
        
        return ans==INT_MAX?-1:ans;
    }
};