class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n= word.size();
        vector<int>big(26,INT_MAX);
        vector<int>small(26,-1);
        set<char>st(word.begin(),word.end());
        for(int i=n-1;i>=0;i--){
            if(word[i]>='a' and word[i]<='z'){
                if(small[word[i]-'a']==-1)
                small[word[i]-'a']=i;
            }
            else{
                big[word[i]-'A']= i;
            }
        }
        int cnt=0;
        for(char c='a';c<='z';c++){
            char cap=c-32;
            if(small[c-'a']!=-1 and big[cap-'A']!=INT_MAX){
                if(big[cap-'A']>small[c-'a']) cnt++;
            }
        }
        return cnt;
        
        
    }
};