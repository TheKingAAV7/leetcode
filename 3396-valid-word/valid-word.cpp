class Solution {
public:
    bool isValid(string word) {
        string vow="aeiouAEIOU";
        bool len, al , vowel,conso;
        len=al=vowel=conso=true;
        conso=false;
        vowel=false;
        if(word.length()>=3) len=true;
        else return false;

        for(char c:word){
            if(!(c>='a' and c<='z' || c>='0' and c<='9' || c>='A' and c<='Z')){
                al=false;
                break;
            }
            if(vow.find(c)==string::npos and ((c>='a' and c<='z') || (c>='A' and c<='Z') )){
              //  cout<<c<<endl;
                conso=true;
            }
            else if(vow.find(c)!=string::npos) vowel=true;
        }
       // cout<<vow<<endl;
        return len and conso and vowel and al;
    }
};