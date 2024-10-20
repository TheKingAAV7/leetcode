class Solution {
public:
    bool parseBoolExpr(string expression) {
        
        stack<char> st;
        bool result;
        bool temp;
        int n = expression.length();
        for(int i = n-1; i >= 0; i--){
            if(expression[i] == '&' || expression[i] == '|' || expression[i] == '!'){
                char oper = expression[i];
                st.pop();
                if(st.top()=='f') temp=false;
                else temp=true;
                st.pop(); 

                if(oper=='!'){
                    st.pop();
                    temp=!temp;
                    if(temp)
                    st.push('t');
                    else st.push('f');
                    continue;

                }    
                
                while(st.top() != ')'){
                    if(st.top() == 'f'){
                        if(oper == '&'){
                            temp &= false;
                        }
                        else if(oper == '|'){
                            temp |= false;
                        }
                       
                    }
                    else if(st.top() == 't'){
                         if(oper == '&'){
                            temp &= true;
                        }
                        else if(oper == '|'){
                            temp |= true;
                        }
                       
                    }
                    st.pop();
                }
                st.pop();
                 if(temp)
                st.push('t');
                else st.push('f');


            }
            else{
                st.push(expression[i]);
            }
        }
        
       
        
        if(st.top()=='t') return true;
        return false;
    }
};