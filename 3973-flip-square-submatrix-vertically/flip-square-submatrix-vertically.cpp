class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int last= x+k-1;
        for(int i=x;i<x+k/2;i++){
             for(int j=y;j<y+k;j++){
                
                swap(grid[i][j],grid[last][j]);
             }
             last--;
        }
        return grid;
    }
};