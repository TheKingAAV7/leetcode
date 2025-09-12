class Solution {
public:
    bool doesAliceWin(string s) {
        string st="aeiou";
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(st.find(s[i])!=string::npos) cnt++;
        }
        if(cnt==0) return false;
        return true;
    }
};