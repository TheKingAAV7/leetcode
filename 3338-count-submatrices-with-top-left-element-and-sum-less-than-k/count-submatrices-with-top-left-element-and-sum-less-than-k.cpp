class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>pref(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up= (i-1>=0)? pref[i-1][j]:0;
                int lef= (j-1>=0)? pref[i][j-1]:0;
                int corn=(i-1>=0 and j-1>=0) ? pref[i-1][j-1]:0;
                int cursm= grid[i][j]+up+lef-corn;
                pref[i][j]=cursm;
                // cout<<cursm<<" ";
                if(cursm<=k) cnt++;
            }
            // cout<<endl;
        }

        return cnt;
    }
};