class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int K) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        K %= (n * m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int k = K;

                int diff = m - j - 1;
                if (k <= diff) {
                    ans[i][j + k] = grid[i][j];
                } else {
                    int row = 1;
                    k -= (diff + 1);

                    int x = k / m;
                    k %= m;

                    row += x;

                    int cr = (i + row) % n;
                    int ncol = k;

                    ans[cr][ncol] = grid[i][j];
                }
            }
        }
        return ans;
    }
};