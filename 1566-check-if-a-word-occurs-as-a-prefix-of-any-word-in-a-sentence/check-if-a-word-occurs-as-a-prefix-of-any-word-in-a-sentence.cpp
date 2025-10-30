class Solution {
public:
    int isPrefixOfWord(string sent, string tar) {
        unordered_map<string,int>mp;
        mp[tar]=1;
        int pos=1;
        string tmp;
        for(char c:sent){
            if(c==' ') {
                tmp.clear();
                pos++;
                continue;
            }
            tmp.push_back(c);
            if(mp.find(tmp)!=mp.end()) return pos;
        }
        return -1;
        
    }
};