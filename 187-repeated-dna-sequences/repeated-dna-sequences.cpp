class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        vector<string>ans;
        int n=s.length();
        if(n<10) return ans;
        string tmp="";
        for(int i=0;i<10;i++){
            tmp.push_back(s[i]);
        }
        mp[tmp]++;
        for(int j=10;j<n;j++){
            tmp.erase(0,1);
            tmp.push_back(s[j]);
            mp[tmp]++;
            if(mp[tmp]==2) ans.push_back(tmp);
        }
        return ans;
    }
};