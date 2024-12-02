class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string tmp="";
        unordered_map<string, int>mp;
        int pos=1;
        
        for(char c: sentence){
           // cnt++;
            if(c==' '){
             tmp="";
             pos++;
            }
            else {
            tmp+=c;
            if(mp.find(tmp)!=mp.end()){
                mp[tmp]=(pos,mp[tmp]);
            }
            else
            mp[tmp]=pos;
            }
            
        }
        if(mp.find(searchWord)!=mp.end()) return mp[searchWord];
        return -1;
    }
};