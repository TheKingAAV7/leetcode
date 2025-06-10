class Solution {
public:
    int maxDifference(string s) {
       int maxev=101,maxod=0;
       int n=s.length();
       vector<int>v(26,0);
       for(char c: s){
        v[c-'a']++;
       } 
       for(int i=0;i<26;i++){
        if(v[i]&1) maxod=max(maxod,v[i]);
        else if(v[i]!=0)maxev=min(maxev,v[i]);
       }
       return maxod-maxev;
    }
};