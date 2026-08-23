class Solution {
public:
    bool isPalindromic(string s) {
        int n=s.length();
        string ans;
        for(int i=0;i<n;i++){
            int x= s[i];
            string cur;
            for(int j=0;j<8;j++){
                int idx= 8-j-1;
                if((x>>idx)&1) cur.push_back('1');
                else cur.push_back('0');
            }
            reverse(cur.begin(),cur.end());
            ans+=cur;
        }

        string rev=ans;
        reverse(rev.begin(),rev.end());
        return ans==rev;
    }
};