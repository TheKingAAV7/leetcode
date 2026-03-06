class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]) cnt++;
        }
        return cnt<=1;
    }
};