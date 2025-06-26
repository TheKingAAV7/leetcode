class Solution {
public:
    string maximumBinaryString(string s) {
        int cnt=0;
        int n=s.length();
        for(char c:s) {
            if(c=='0') cnt++;
        }
        string ans="";
        int pos=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ans.push_back(s[i]);
            }
            else {
                pos=i;
                break;
            }
        }
        if(pos==-1) return ans;
        
        for(int i=0;i<cnt-1;i++){
            ans.push_back('1');
        }
        ans.push_back('0');
        while(ans.size()<n) ans.push_back('1');
        return ans;
    }
};