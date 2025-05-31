class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
      map<char,set<char>>mp;
      for(auto it:mappings){
        mp[it[0]].insert(it[1]);
      }  
     
      if(s.find(sub)!=string::npos) return true;
      int n=s.length();
      int m=sub.length();
      for(int i=0;i<n;i++){
        int pos1=i,pos2=0;
        
        while(pos1<n and pos2<m){
            if(s[pos1]==sub[pos2]){
                pos1++;
                pos2++;
            }
            else{
                if(mp.find(sub[pos2])!=mp.end() and mp[sub[pos2]].find(s[pos1])!=mp[sub[pos2]].end()){
                    pos1++;
                    pos2++;
                }
                else break;
            }
        }
        if(pos2==m) return true;
        
      }
      return false;
    }
};