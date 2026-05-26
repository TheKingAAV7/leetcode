class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>st(word.begin(),word.end());
        int cnt=0;
        for(char c='a';c<='z';c++){
            char cap= c-32;
            if(st.count(c) and st.count(cap)) cnt++;
        }
        return cnt;
    }
};