class Solution {
public:
    bool isSubstringPresent(string s) {
        int n=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        unordered_set<string>st;
        for(int i=0;i<n-1;i++){
            string tmp=string(1,s[i])+s[i+1];
            st.insert(tmp);
        }
        for(int i=0;i<n-1;i++){
            string tmp=string(1,t[i])+t[i+1];
            if(st.find(tmp)!=st.end()) return true;
        }
        return false;
    }
};