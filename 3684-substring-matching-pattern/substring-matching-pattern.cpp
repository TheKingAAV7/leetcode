class Solution {
public:
    bool hasMatch(string s, string p) {
        int i=p.find('*');
        int n=p.length();
        string s1=p.substr(0,i);
        string s2=p.substr(i+1,(n-(i+1)));
        bool f1=false,f2=false;
        auto it1=-1,it2=-1;
        if(s1=="") f1=true;
        else{
             it1=s.find(s1);
            if(it1!=string::npos){
                s.erase(it1,s1.length());
                f1=true;
            }

        }
        if(s2=="") f2=true;
        else{
           it2=s.rfind(s2);
            if(it2!=string::npos){
                if(it2>=it1){
                s.erase(it2,s2.length());
                f2=true;
                }
            } 
        }
        return f1 and f2;
    }
};