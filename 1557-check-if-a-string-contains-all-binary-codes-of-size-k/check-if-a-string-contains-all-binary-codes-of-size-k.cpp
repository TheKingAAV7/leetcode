class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();
        set<string>st;
        for(int i=0;i+k<=n;i++){
            string cur;
            for(int j=i;j<i+k;j++){
                cur.push_back(s[j]);
            }
      
            st.insert(cur);
        }
        int req= pow(2,k);
     
        return int(st.size())==req;
    }
};