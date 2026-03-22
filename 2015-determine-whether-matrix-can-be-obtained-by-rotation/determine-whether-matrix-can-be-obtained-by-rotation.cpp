class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        int m=mat[0].size();

        /*  
         00  02
         01  12
         03  22
         10  01
         11  11
         12  21
         20  00
         21  10
         22  20
        */

        for(int turn =0;turn<4;turn++){
        vector<vector<int>>tmp(n,vector<int>(n,0));
        int ro=0;
        int col=n-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                tmp[i][j]= mat[ro][col];
                ro=(ro+1)%n;
            }
            col=col-1;
        }
        if(target==tmp) return true;
        mat=tmp;
        }
        return false;

    }
};