class Solution {
public:
    int possibleStringCount(string word) {
        int cnt=1;
        int ans=0;
        char prev='.';
        for(char c:word){
            if(c==prev){
                cnt++;
            }
            else {
                ans+=(cnt-1);
                prev=c;
                cnt=1;
            }
        }
     
        ans+=(cnt-1);
        return ans+1;
    }
};