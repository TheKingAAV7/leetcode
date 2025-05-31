class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        bool len,lc,uc,od,sp;
        string tmp="!@#$%^&*()-+";
        len=lc=uc=od=sp=false;
        int n=s.length();
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) return false;
        }
        if(s.length()>=8) len=true;
        for(char i:s){
            if(i>='a' and i<='z') lc=true;
            else if(i>='A' and i<='Z')uc=true;
            else if(i>='0' and i<='9') od=true;
            else if(tmp.find(i)!=string::npos) sp=true;

        }
        return len and lc and uc and od and sp;
    }
};