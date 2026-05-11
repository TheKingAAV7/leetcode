class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto &x:nums){
            string s= to_string(x);
            int sz= s.length();
            for(int i=0;i<sz;i++) ans.push_back(s[i]-'0');
        }
        return ans;
    }
};