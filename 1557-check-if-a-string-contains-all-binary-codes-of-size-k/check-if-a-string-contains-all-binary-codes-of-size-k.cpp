class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();
        // find all the substrings of length k and put them into a set
        set<string>st;
        for(int i=0;i<n;i++){
            if( (i+k) <= n ){
            string currentSubstring="";
            for(int j=i;j<i+k;j++){
                currentSubstring.push_back(s[j]);
            }
            // we have the substring starting from i of length k
            st.insert(currentSubstring);
            }
        }
        int requiredCount= pow(2,k);
        if(st.size()==requiredCount) return true;
        return false;
    }
};