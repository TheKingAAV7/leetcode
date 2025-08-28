class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        // 0  1 2
        // -1 -2
        int n=grid.size(),m=grid[0].size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int diff=i-j;
                mp[diff].push_back(grid[i][j]);
            }
        }
        for(auto &it:mp){
            int par=it.first;
            if(par<0){
                sort(mp[par].begin(),mp[par].end(),greater<int>());
            }
            else{
                sort(mp[par].begin(),mp[par].end());
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int diff=i-j;
                grid[i][j]=mp[diff].back();
                mp[diff].pop_back();
            }
        }
        return grid;
    }
};