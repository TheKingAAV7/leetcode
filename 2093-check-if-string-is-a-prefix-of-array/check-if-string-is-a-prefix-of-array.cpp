class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string res="";
        for(auto it:words){
            res+=it;
        }
        int n=words.size();
        int pos=n-1;
        while(res.size()>s.size()){
            int sz=words[pos].size();
            while(sz--) res.pop_back();
            pos--;
        }
        return res==s;
    }
};