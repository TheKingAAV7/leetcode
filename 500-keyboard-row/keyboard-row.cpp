class Solution {
public:
    vector<string> findWords(vector<string>& words) {
       vector<string>ans;

       string up= "qwertyuiop";
       string mid= "asdfghjkl";
       string down="zxcvbnm";
       for(int i=0;i<words.size();i++){
        int cntu=0,cntm=0,cntd=0;
        int m=words[i].length();
        for(char c:words[i]){
            if(up.find(tolower(c))!=string::npos){
                cntu++;
            }
            else if(mid.find(tolower(c))!=string::npos) cntm++;
            else cntd++;
        }
        if(cntu==m || cntm==m || cntd==m)  ans.push_back(words[i]);
       }
       return ans;
    }
};