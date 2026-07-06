class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int mx=0;
        map<int,int>mp;
        for(int i:nums){
            string s= to_string(i);
            sort(s.begin(),s.end());
            int cur= s.back()-s[0];
            mp[cur]+=i;
        }
        int ans= (prev(mp.end()))->second;
        return ans;
    }
};