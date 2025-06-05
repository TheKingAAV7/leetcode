class Solution {
private:
char f(int node,vector<vector<int>>&v,vector<int>&vis){
    if(vis[node]) return 'z'+1;
    vis[node]=1;
    char mini=node+'a';
    for(auto it:v[node]){
        char tc=f(it,v,vis);
        mini=min(tc,mini);
    }
    return mini;
    
}
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>>v(26);
        int n=s1.length();
        for(int i=0;i<n;i++){
            v[s1[i]-'a'].push_back(s2[i]-'a');
            v[s2[i]-'a'].push_back(s1[i]-'a');
        }
        
        for(auto &c:baseStr){
            vector<int>vis(26,0);
            char tmp=f(c-'a',v,vis);
            c=tmp;
        }
        return baseStr;
    }
};