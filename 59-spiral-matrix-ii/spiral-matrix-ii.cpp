class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int cur=1;
        int dx[]= {0,1,0,-1};
        int dy[]= {1,0,-1,0};
        int i=0,j=0;
        int dir=0;
        while(cur<=n*n){
            
            ans[i][j]=cur;

            cur++;
            i+=dx[dir];
            j+=dy[dir];
            if(i>=n || i<0 || j>=n || j<0 || ans[i][j]!=0){
                i-=dx[dir];
                j-=dy[dir];
                dir=(dir+1)%4;
                i+=dx[dir];
                j+=dy[dir];
            }
        }
        return ans;
    }
};