class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int cnt=0;
        char prev='-';
        int n=word.length();
        for(int i=0;i<n;i++){
            if(word[i]!=prev || cnt==9){
                if(prev!='-'){
                ans+= to_string(cnt) + prev;
                }
                prev=word[i];
                cnt=1;
            }
           else if(word[i]==prev) cnt++;

        }
        
        return ans+ to_string(cnt)+prev;
    }

};