class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
       
        vector<string>ans;
        
        for(auto &s:queries){
            bool reached= false;
            for(auto &t:dict){
                if(s.length()!=t.length()) continue;
                int cnt=0;
                for(int i=0;i<s.length();i++) cnt+=(s[i]!=t[i]);
                if(cnt<=2) {
                 reached= true;
                 break;
                }
            }
            if(reached){
                ans.push_back(s);
            }
        }
        return ans;
    }
};