class Solution {
public:
    char repeatedCharacter(string s) {
        int n=s.length();
        vector<int>vis(26,0);
        for(int i=0;i<n;i++){
            vis[s[i]-'a']++;
            if(vis[s[i]-'a']>=2) return s[i];
        }
        
        return 'c';
    }
};