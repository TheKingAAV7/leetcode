class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int n=s.length();
        string tmp="";
        for(int i=0;i<n;i++){
            
            tmp.push_back(s[i]);
            if(((int)(tmp.size()))==k){
                ans.push_back(tmp);
                tmp="";
            }
        }
        if(tmp=="") return ans;
        while(tmp.size()<k){
            tmp.push_back(fill);
        }
        ans.push_back(tmp);
        return ans;
    }
};