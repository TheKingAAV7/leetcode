class Solution {
public:
    string countAndSay(int n1) {
        string ans="1";
        for(int i=0;i<n1-1;i++){
           string tmp="";
           int n=ans.length();
           char c='-';
           int cnt=0;
           for(int i=0;i<n;i++){
                if(c=='-'){
                    c=ans[i];
                    cnt=1;
                }
                else if(c!='-' and c==ans[i] ) cnt++;
                else{
                    tmp+=to_string(cnt);
                    tmp.push_back(c);
                    c=ans[i];
                    cnt=1;
                }
           }
           tmp+=to_string(cnt);
           tmp.push_back(c);

           ans=tmp;
           

           
        }
        return ans;
    }
};