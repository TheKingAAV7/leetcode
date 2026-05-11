class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n= grid.size();
        for(int j=0;j<n;j++){
            bool one=false;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1){
                    one=true;
                    break;
                }
            }
            if(!one) return j;
        }
        return -1;
    }
};