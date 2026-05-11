class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto &x:nums){
            string s= to_string(x);
            int sz= s.length();
            for(char &c:s) ans.push_back(c-'0');
        }
        return ans;
    }
};