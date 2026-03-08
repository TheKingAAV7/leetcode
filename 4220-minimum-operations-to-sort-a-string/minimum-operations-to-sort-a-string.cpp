class Solution {
public:
/*
approach:
Try to move smallest to the left and la

xxxxxxxx maxi mini xxxx
d bbbb a
abbbdb
maximum answer can be 3

 maxi xxxx mini mini
 xxxx maxi xxxx mini
 xxxx maxi xxxx minixxx
 xxx mini xxx maxi xxx mini xxx
 xxx mini xxx maxi xxx mini 
 mini xxx maxi xxxx mini
 mini xxx maxi xxxx minixxx
jgg
gjxxxg

*/
    int minOperations(string s) {
        int n=s.length();
        string tmp=s;
        sort(tmp.begin(),tmp.end());
        if(s==tmp) return 0;
        if(n==2) return -1;
        char mini=tmp[0];
        char maxi=tmp.back();
        if(s[0]==mini and s.back()==maxi) return 1;
        if(s[0]==mini || s.back()==maxi) return 1;
        {
        string ss= s;
        sort(ss.begin(),ss.begin()+n-1);
        sort(ss.begin()+1,ss.end());
        if(ss==tmp) return 2;
        }
        {
        string ss= s;
        sort(ss.begin()+1,ss.end());
        sort(ss.begin(),ss.begin()+n-1);
        if(ss==tmp) return 2;
        }
        if(s.back()==mini and s[0]==maxi) return 3;
        return 2;
    }
};