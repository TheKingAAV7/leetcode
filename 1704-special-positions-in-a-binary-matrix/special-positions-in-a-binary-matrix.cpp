class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    int sm1=0, sm2=0;
                    for(int k=0;k<n;k++) sm1+=mat[k][j];
                    for(int k=0;k<m;k++) sm2+=mat[i][k];
                    if(sm1==sm2 and sm1==1) cnt++;
                }
            }
        }
        return cnt;
    }
};