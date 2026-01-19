class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n= mat.size();
        int m= mat[0].size();
        int ans=0;

        vector<vector<int>>pref(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cur= mat[i][j];
                
                int up= (i-1>=0)?pref[i-1][j]:0;
                int left= (j-1>=0)? pref[i][j-1] : 0;
                int common= (i-1>=0 and j-1>=0)? pref[i-1][j-1]:0;
                pref[i][j]= cur + up + left - common;
            }
        }
        for(int len=min(n,m);len>0;len--){
            for(int i=0;i+len-1<n;i++){
                for(int j=0;j+len-1<m;j++){
                    int dx= i+len-1;
                    int dy= j+len-1;
                    // find the total sm;
                    int total= pref[dx][dy];
                    int up= (i-1>=0)?pref[i-1][dy]:0;
                    int left= (j-1>=0)? pref[dx][j-1] : 0;
                    int common= (i-1>=0 and j-1>=0)? pref[i-1][j-1]:0;
                    int sm= total-up-left+common;
                    if(sm<=threshold) return len;
                }
            }
        }
        return 0;
    }
};