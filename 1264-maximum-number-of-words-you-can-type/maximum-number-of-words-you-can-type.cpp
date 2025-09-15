class Solution {
public:
    int canBeTypedWords(string s, string bl) {
        int n=s.length();
        vector<int>vis(26,0);
        for(char c:bl){
            vis[c-'a']=1;
        }
        int cnt=0;
        bool prev=true;
        int st=0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(prev) cnt++;
                prev=true;
            }
            else{
                if(prev){
                    if(vis[s[i]-'a'])
                    prev=false;
                }

            }
        }
        if(prev) cnt++;
        return cnt;
    }
};