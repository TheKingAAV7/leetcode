class Solution {
public:
    string countAndSay(int n1) {
        if(n1==1) return "1";
        string ans=countAndSay(n1-1);
       
        int n=ans.length();
        char c='-';
        int cnt=0;
        string tmp="";
        for(int i=0;i<n;i++){
            if(c=='-'){
                c=ans[i];
                cnt=1;
            }
            else if(c!='-' and ans[i]==c){
                cnt++;
            }
            else{
                string stmp=to_string(cnt);
                tmp+=stmp;
                tmp.push_back(c);
                c=ans[i];
                cnt=1;
            }
        }
        string stmp=to_string(cnt);
        tmp+=stmp;
        tmp.push_back(c);

        return tmp;

    }
};