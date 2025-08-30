class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& bd) {
        int n=bd.size(),m=bd[0].size();
        // row check
        for(int i=0;i<n;i++){
            set<char>st;
            for(int j=0;j<n;j++){
                if(bd[i][j]!='.'){
                if(st.find(bd[i][j])!=st.end()){
                   // cout<<i<<" "<<j<<endl;
                 return false;
                }
                st.insert(bd[i][j]);
                }
            }
          
            
        }
       
        for(int i=0;i<n;i++){
            set<char>st;
            for(int j=0;j<n;j++){
                if(bd[j][i]!='.'){
                if(st.find(bd[j][i])!=st.end()){
                     //cout<<"YSE"<<endl;
                 return false;
                }
                st.insert(bd[j][i]);
                }
            }
           
        }
        for(int i=0;i<n;i+=3){
            for(int j=0;j<n;j+=3){
                set<char>st;
                for(int i1=0;i1<3;i1++){
                    for(int j1=0;j1<3;j1++){
                        if(bd[i+i1][j+j1]!='.'){
                        if(st.find(bd[i+i1][j+j1])!=st.end()){
                           
                         return false;
                        }
                        st.insert(bd[i+i1][j+j1]);
                        }
                    }
                }
            }
        }
        return true;
    }
};