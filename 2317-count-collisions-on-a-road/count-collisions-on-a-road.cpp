class Solution {
public:
    int countCollisions(string s) {
        int n=s.length();
        stack<char>st;
        int ans=0;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(s[i]=='L'){
                // RS
                if(st.top()=='R'){
                    ans+=2;
                    st.pop();
                    while(!st.empty() and st.top()=='R'){
                        ans+=1;
                        st.pop();
                    }
                    st.push('S');
                    st.push('S');
                }
                else if(st.top()=='S'){
                    ans+=1;
                    st.push('S');
                }
                else{
                    st.push(s[i]);
                }
            }
            else if(s[i]=='S'){
                if(st.top()=='L'){
                    st.push(s[i]);
                }
                else if(st.top()=='R'){
                    while(!st.empty() and st.top()=='R'){
                        ans+=1;
                        st.pop();
                    }
                    st.push(s[i]);
                }
                else{
                    st.push('S');
                }
            }
            else{
                //LS
              st.push(s[i]);
            }
        }
        return ans;
    }
};