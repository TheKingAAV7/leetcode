class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int>ans;
        stack<int>st;
        int n=ast.size();
        for(int i=0;i<n;i++){
            if(ast[i]>0) {
                st.push(ast[i]);
            }
            else{
                int tmp=abs(ast[i]);
                while(!st.empty() and tmp>0){
                    if(st.top()<0) break;
                    if(st.top()<tmp){
                       // tmp-=st.top();
                        st.pop();
                    }
                    else if(st.top()==tmp){
                        tmp=0;
                        st.pop();
                        break;
                    }
                    else{
                        tmp=0;
                        break;    
                    }
                }
                if(tmp!=0){
                    st.push(-1*tmp);
                }
            }
        }
        while(!st.empty()){
            int f=st.top();
            st.pop();
            ans.push_back(f);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};