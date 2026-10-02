class Solution {
public:
    vector<string> generateParenthesis(int n) {
        n*=2;
        vector<string>ans;

        auto valid=[&](string &s)->bool{
            stack<char>st;
            int len= s.length();
            for(int i=0;i<n;i++){
                if(s[i]=='(') st.push(s[i]);
                else {
                    if( !st.empty() and st.top()=='(') st.pop();
                    else return false;
                }
            }
            return st.empty();
        };
        for(int x=0;x<(1<<n);x++){
            string s;
            for(int i=0;i<n;i++){
                int idx= n-i-1;
                if((x>>idx)&1) s.push_back('(');
                else s.push_back(')');
            }
            // cout<<s<<endl;
            if(valid(s)) ans.push_back(s);
        }
        return ans;
    }
};