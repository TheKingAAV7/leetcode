class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            vector<int>v=grid[i];
            for(int j=0;j<n;j++){
                vector<int>tmp;
                for(int k=0;k<n;k++) tmp.push_back(grid[k][j]);
                if(tmp==v) cnt++;
            }
        }
        return cnt;
    }
};