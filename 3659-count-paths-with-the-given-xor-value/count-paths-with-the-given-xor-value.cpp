class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> grid;
    int k, n, m;
    vector<vector<vector<int>>> dp;

    int f(int i, int j, int curr){
        if(i >= n || j >= m) return 0;
        curr ^= grid[i][j];  
        if(i == n - 1 && j == m - 1){
            return curr == k;
        }
        
        if (dp[i][j][curr] != -1) return dp[i][j][curr];
        int right = f(i, j + 1, curr) % mod;
        int down = f(i + 1, j, curr) % mod;
        return dp[i][j][curr] = (right + down) % mod;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        this->grid = grid;
        this->k = k;
        n = grid.size();
        m = grid[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(20, -1))); 
        return f(0, 0, 0);
    }
};