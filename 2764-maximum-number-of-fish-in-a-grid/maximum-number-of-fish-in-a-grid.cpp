class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    bool val(int x, int y, int rows, int cols, vector<vector<int>>& grid) {
        if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != 0) return true;
        return false;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();

        // Lambda function to calculate the max fish starting from a given cell
        auto f = [&](pair<int, int> start, vector<vector<int>>& grid) -> int {
            priority_queue<pair<int, pair<int, int>>> pq;
            vector<vector<int>> dist(n, vector<int>(m, -1));
            dist[start.first][start.second] = grid[start.first][start.second];
            pq.push({grid[start.first][start.second], start});
            int fishSum = grid[start.first][start.second];
            grid[start.first][start.second] = 0;

            while (!pq.empty()) {
                auto [d, pos] = pq.top();
                int x = pos.first, y = pos.second;
                pq.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (val(nx, ny, n, m, grid)) {
                        fishSum += grid[nx][ny];
                        pq.push({grid[nx][ny], {nx, ny}});
                        grid[nx][ny] = 0;
                    }
                }
            }
            return fishSum;
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    vector<vector<int>> tempGrid = grid; // Copy grid for each call
                    pair<int, int> start = {i, j};
                    int tmp = f(start, tempGrid);
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};
