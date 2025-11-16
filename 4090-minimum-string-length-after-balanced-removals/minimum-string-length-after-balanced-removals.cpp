class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(s[i]);
            else{
                if(st.top()==s[i]) st.push(s[i]);
                else st.pop();
            }
        }
        return st.size();
    }
};