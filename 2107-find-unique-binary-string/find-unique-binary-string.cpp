class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_map<string,int>mp;
        for(auto &it:nums) mp[it]++;
        string ans;
        auto f=[&](auto &&self,int i, int& n, string &s)->void{
            if(i>=n) {
                if(mp.find(s)==mp.end()){
                    ans=s;
                    return;
                }
                return ;
            }
            s.push_back('0');
            self(self,i+1,n,s);
            s.pop_back();
            s.push_back('1');
            self(self,i+1,n,s);
            s.pop_back();
            return;
        };
        string cur;
        f(f,0,n,cur);
        return ans;
    }
};