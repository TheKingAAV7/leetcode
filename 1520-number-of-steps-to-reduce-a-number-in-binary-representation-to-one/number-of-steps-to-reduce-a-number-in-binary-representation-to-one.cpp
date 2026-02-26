class Solution {
public:
    int numSteps(string s) {
         int n=s.length();
         int cnt=0;
         auto add=[&](string &s)->void{
            int carry=1;
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='1'){
                    s[i]='0';
                }
                else {
                    s[i]='1';
                    carry=0;
                    break;
                }
            }
            if(carry) {
                reverse(s.begin(),s.end());
                s.push_back('1');
                reverse(s.begin(),s.end());
            }
            return ;
         };
         while(s!="1"){
            if(s.back()=='1') add(s);
            else s.pop_back();
         //   cout<<s<<endl;
            cnt++;
         }    
         return cnt;
    }
};