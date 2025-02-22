class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        bool odd=true;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(odd){
                for(int j=0;j<m;j+=2) ans.push_back(grid[i][j]);
            }
            else{
                vector<int>tmp;
                for(int j=1;j<m;j+=2) tmp.push_back(grid[i][j]);
                reverse(tmp.begin(),tmp.end());
                for(int l:tmp) ans.push_back(l);

            }
            odd=!odd;
        }
        return ans;
    }
};