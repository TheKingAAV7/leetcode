class Solution {
public:
    bool isCircularSentence(string s) {
        vector<vector<char>>v;
        for(int i=0;i<s.size();i++){
         char a=s[i];
         
         while(i<s.size() and s[i]!=' '){
            i++;
         }
         char b=s[i-1];
         v.push_back({a,b});
        }
        for(int i=0;i<v.size()-1;i++){
            if(v[i][1]!=v[i+1][0]) return false;
        }
        if(v.back()[1]!=v[0][0]) return false;

        return true;;
    }
};