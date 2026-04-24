class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int cnt=0;
        int dir=0;
        for(char &c:s){
            if(c=='L') dir--;
            else if(c=='R') dir++;
            else cnt++;
        }
        return abs(dir) + cnt;
    }
};