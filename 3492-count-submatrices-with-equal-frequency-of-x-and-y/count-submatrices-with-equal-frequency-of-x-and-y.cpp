class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>pref(n,vector<int>(m,0));
        vector<vector<int>>xp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up= (i-1>=0)?pref[i-1][j]:0;
                int lef= (j-1>=0)?pref[i][j-1]:0;
                int corn=(i-1>=0 and j-1>=0)?pref[i-1][j-1]:0;
                int cur= (grid[i][j]=='X')?1:(grid[i][j]=='Y')?-1:0;
                int up1= (i-1>=0)?xp[i-1][j]:0;
                int lef1= (j-1>=0)?xp[i][j-1]:0;
                int corn1=(i-1>=0 and j-1>=0)?xp[i-1][j-1]:0;
                int cur1= (grid[i][j]=='X')?1:0;
                pref[i][j]= up+lef-corn+cur;
                xp[i][j]=up1+lef1-corn1+cur1;
                if(pref[i][j]==0 and xp[i][j]>=1) cnt++;
            }
        }
        return cnt;
    }
};