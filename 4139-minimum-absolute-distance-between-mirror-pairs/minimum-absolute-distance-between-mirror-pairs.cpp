class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<string,int>mp;
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            
            string cur= to_string(nums[i]);
            if(mp.find(cur)!=mp.end())
            ans= min(ans,i-mp[cur]);
            while(cur.back()=='0') cur.pop_back();
            reverse(cur.begin(),cur.end());
            mp[cur]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};