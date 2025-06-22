class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string>ans;
        string tmp="";
        for(int i=0;i<n;i++){
            if(tmp.size()==k){
                ans.push_back(tmp);
                tmp="";
            }
             tmp.push_back(s[i]);
        }
        if(tmp=="") return ans;
        while(tmp.size()<k) tmp.push_back(fill);
        ans.push_back(tmp);
        return ans;
    }
};