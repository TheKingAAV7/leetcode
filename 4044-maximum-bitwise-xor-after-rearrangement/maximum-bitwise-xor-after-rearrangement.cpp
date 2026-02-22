class Solution {
public:
    string maximumXor(string s, string t) {
        int cnt0=0;
        int cnt1=0;
        for(char c:t){
            if(c=='0') cnt0++;
            else cnt1++;
        }
        string ans;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                if(cnt0>0){
                    ans.push_back('1');
                    cnt0--;
                }
                else ans.push_back('0');
            }
            else{
                if(cnt1>0){
                    ans.push_back('1');
                    cnt1--;
                }
                else ans.push_back('0');
            }
        }
        return ans;
    }
};