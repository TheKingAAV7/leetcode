class Solution {
public:
    bool hasSameDigits(string s) {
        string tmp=s;
        int n=tmp.length();
        while(tmp.length()>2){
            string t1="";
            for(int i=1;i<tmp.length();i++){
                t1.push_back(((tmp[i-1]-'0')+(tmp[i]-'0'))%10+'0');
            }
          //  cout<<t1<<endl;
            tmp=t1;
        }
        return tmp[0]==tmp[1];
    }
};