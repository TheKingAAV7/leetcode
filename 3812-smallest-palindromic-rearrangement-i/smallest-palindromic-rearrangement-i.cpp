class Solution {
public:
    string smallestPalindrome(string s) {
        vector<char>v;
        int n= s.length();
        for(int i=0;i<n/2;i++){
            v.push_back(s[i]);
        }
        sort(v.begin(),v.end());
        int pos=0;
        for(int i=0;i<n/2;i++){
            s[i]=v[pos];
            s[n-i-1]=v[pos++];
        }
        return s;
    }
};