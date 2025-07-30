class Solution {
public:
    int numSplits(string s) {
        map<char,int>mp,mp1;
        for(char c:s){
            mp1[c]++;
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
            mp1[s[i]]--;
            if(mp1[s[i]]==0) mp1.erase(s[i]);
            mp[s[i]]++;
            if(mp.size()==mp1.size()) ans++;
        }
        return ans;
    }
};