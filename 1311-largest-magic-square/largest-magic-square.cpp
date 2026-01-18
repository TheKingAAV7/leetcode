class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int ans=1;

        auto check=[&](int lefr, int lefc, int rigr, int rigc)->bool{
            set<int>st;
            int diag1=0;
            int diag2=0;
            int p=lefr;
            int q= lefc;
            while(p<=rigr and q<=rigc){
                diag1+=grid[p][q];
                p++;
                q++;
            }
             p= lefr;
             q= rigc;

             while(q>=0 and p<=rigr){
                diag2+=grid[p][q];
                p++;
                q--;
             } 

             
             for(int i=lefr;i<=rigr;i++){
                int sm=0;
                for(int j=lefc;j<=rigc;j++){
                    sm+=grid[i][j];
                }   
                st.insert(sm);
                if(st.size()>1) return false;
             }
             for(int j=lefc;j<=rigc;j++){
                int sm=0;
                for(int i=lefr;i<=rigr;i++){
                    sm+=grid[i][j];
                }
                st.insert(sm);
                if(st.size()>1) return false;
             }
             return *st.begin()==diag1 and diag1==diag2;
        };
        for(int len = 2; len<=min(n,m);len++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int lefr= i;
                    int lefc= j;
                    int rigr= i+len-1;
                    int rigc= j+len-1;

                    if(rigr<n and rigc<m){
                       if( check(lefr,lefc,rigr,rigc)){
                        ans = max(ans,len);
                       }
                    } 
                }
            }
        }
        return ans;
    }
};