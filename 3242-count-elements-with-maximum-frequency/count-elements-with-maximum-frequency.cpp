class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        int ans=0;
        for(int i:nums){
             mp[i]++;
        }
        int maxi=0;
        for(auto it:mp){
            maxi=max(maxi,it.second);
        }
        for(auto it:mp){
            if(it.second==maxi) ans+=(it.second);
        }
        return ans;
    }
};