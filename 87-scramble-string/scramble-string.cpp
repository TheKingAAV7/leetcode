class Solution {
public:
    unordered_map<string,int>mp;
    int dp[30][30][30][30];
    bool f(int i1, int j1,int i2, int j2, string &s1,string &s2){
        if(i1==j1){
            return s1[i1]==s2[i2]; // doubt
        }
        if(dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];
        bool ans=false;
        for(int i=i1;i<j1;i++){
            // 01234
            // eatgr   (2-4) (0-1)
             // rgeat   (0-1) (2-4)   (0-2) (3,4)
             // 01234
            
            // string lef=s1.substr(i1,lefsz);
            // string rig=s1.substr(i1+1,rigsz);
            // no change  
            int lenLeft = i - i1 + 1;
            // cout<<i1<<" "<<i<<" "<<i2<<" "<<i<<endl;
            // cout<<i+1<<" "<<j1<<" "<<i+1<<" "<<j2<<endl;
            int rigsz=(i-i1+1);
            int lefsz=(j1-(i+1)+1);
            // cout<<(i+1)<<" r"<<j1<<"r "<<i2<<"r "<<i2+lefsz-1<<endl;
            // cout<<i1<<" r"<<i<<"r "<<i2+lefsz<<"r "<<j2<<endl;

            bool a1=f(i1,i,i2,i2+lenLeft-1,s1,s2);
            bool a2=f(i+1,j1,i2+lenLeft,j2,s1,s2);
            
            ans |=(a1 & a2);
            if(ans){
                break;
            }

            
            bool b1=f(i1,i,j2-lenLeft+1,j2,s1,s2);
            bool b2=f(i+1,j1,i2,j2-lenLeft,s1,s2);
            ans |=(b1 & b2);
            if(ans) break;
        }
        
        return dp[i1][j1][i2][j2]=ans;
    }
    bool isScramble(string s1, string s2) {
     /*

    it's a dp problem , 
    we can consider a string split somewhere and scramble
    first, let's right recursion

     */
     for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            for(int k=0;k<30;k++){
                for(int l=0;l<30;l++) dp[i][j][k][l]=-1;
            }
        }
     }
     int n=s1.length();
     bool ans=f(0,n-1,0,n-1,s1,s2);
     return ans;
    }
};