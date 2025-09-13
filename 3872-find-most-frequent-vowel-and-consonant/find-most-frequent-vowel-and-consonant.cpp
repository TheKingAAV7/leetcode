class Solution {
public:
    int maxFreqSum(string s) {
       string vow="aeiou";
       vector<int>v(26,0);
       int n=s.length();
       for(int i=0;i<n;i++) v[s[i]-'a']++;
       
       int a=0,b=0;
       for(int i=0;i<26;i++){
        char tmp=i+'a';
        if(vow.find(tmp)!=string::npos){
            a=max(v[i],a);
        }
        else b=max(b,v[i]);
       }
       return a+b;
    }
};