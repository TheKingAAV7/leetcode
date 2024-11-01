class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        char prev='-';
        int cnt=1;
        for(char c: s){
          if(c==prev){

             if(cnt<2){
                ans+=c;
                cnt++;
             }   
          }else{
             ans+=c;
            prev=c;
            cnt=1;
          }
        }
        return ans;
    }
};