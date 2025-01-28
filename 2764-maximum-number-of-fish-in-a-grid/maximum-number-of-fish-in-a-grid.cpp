class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    // Helper function to check if a cell is valid
    bool val(int x, int y, int rows, int cols, vector<vector<int>>& grid) {
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != 0;
    }

    // DFS function to calculate the fish collected from a starting cell
    int dfs(int x, int y, vector<vector<int>>& grid) {
        int fish = grid[x][y];
        grid[x][y] = 0; // Mark as visited

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (val(nx, ny, grid.size(), grid[0].size(), grid)) {
                fish += dfs(nx, ny, grid);
            }
        }

        return fish;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxFish = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    vector<vector<int>> tempGrid = grid; // Copy the grid for safe exploration
                    maxFish = max(maxFish, dfs(i, j, tempGrid));
                }
            }
        }

        return maxFish;
    }
};
