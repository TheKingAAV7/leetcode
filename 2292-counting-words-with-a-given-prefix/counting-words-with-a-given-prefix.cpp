class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
       int n=pref.size();
       int ans=0;
       for(auto it:words){
        string tmp=it.substr(0,n);
        if(tmp==pref) ans++;
       } 
       return ans;
    }
};