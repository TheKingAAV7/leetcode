class Solution {
public:
    int maxDepth(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

       stack<char>st;
       int maxi=INT_MIN;
       for(int i=0;i<s.length();i++){
        
        if(s[i]=='(' ){
            st.push(s[i]);
            
        }
        else if(s[i]==')'){
            st.pop();
        }         
           int n=st.size();
            maxi=max(n,maxi);
       }
       return maxi;
    }
};