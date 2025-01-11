class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.length()) return false;
        if(k==s.length()) return true;
        vector<int>v(26,0);
        for(char c:s){
            v[c-'a']++;
        }
        int cnt=0;
        for(int i:v){
            if(i&1) cnt++;
        }
        cnt--;
        if(k>cnt) return true;
        return false;
    }
};