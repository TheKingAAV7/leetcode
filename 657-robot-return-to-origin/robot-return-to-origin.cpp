class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;
        for(char c:moves){
            if(c=='R') j++;
            else if(c=='L') j--;
            else if(c=='D') i++;
            else i--;
        }
        return i==0 and j==0;
    }
};