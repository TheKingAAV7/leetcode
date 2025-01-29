class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
    
        vector<int>st;
        int n=ast.size();
        for(int i=0;i<n;i++){
            if(ast[i]>0) {
                st.push_back(ast[i]);
            }
            else{
                int tmp=abs(ast[i]);
                while(!st.empty() and tmp>0){
                    if(st.back()<0) break;
                    if(st.back()<tmp){
                       // tmp-=st.top();
                        st.pop_back();
                    }
                    else if(st.back()==tmp){
                        tmp=0;
                        st.pop_back();
                        break;
                    }
                    else{
                        tmp=0;
                        break;    
                    }
                }
                if(tmp!=0){
                    st.push_back(-1*tmp);
                }
            }
        }
        
        return st;

    }
};