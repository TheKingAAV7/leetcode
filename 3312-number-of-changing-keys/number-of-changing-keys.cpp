class Solution {
public:
    int countKeyChanges(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
       
        int cnt=0;
        for(int i=1;i<s.length();i++){
            if(s[i-1]!=s[i]) cnt++;
        }
        return cnt;
    }
};