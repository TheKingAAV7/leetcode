#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> row = {-1, 1, 0, 0};
    vector<int> col = {0, 0, -1, 1};

    void dfs(int i, int j,
             vector<vector<vector<int>>>& dp,
             vector<vector<int>>& vis,
             vector<vector<int>>& grid,
             int n, int m) {
        if (vis[i][j]) return;
        vis[i][j] = 1;

        for (int k = 0; k < 4; ++k) {
            int ni = i + row[k], nj = j + col[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m
                && grid[ni][nj] > grid[i][j]) {
                if (!vis[ni][nj]) {
                    dfs(ni, nj, dp, vis, grid, n, m);
                }
                // paths from (i,j) going in direction k
                dp[i][j][k] = (dp[ni][nj][4] + 1) % 1000000007;
            }
        }

        // total paths of length ≥ 2 from (i,j)
        int total = 0;
        for (int k = 0; k < 4; ++k) {
            total = (total + dp[i][j][k]) % 1000000007;
        }
        dp[i][j][4] = total;
    }

public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int MOD = 1000000007;

        // dp[i][j][0..3]: number of inc. paths from (i,j) going in each dir (length≥2)
        // dp[i][j][4]: sum of dp[i][j][0..3]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(5, 0)));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // fill dp via DFS
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j]) {
                    dfs(i, j, dp, vis, grid, n, m);
                }
            }
        }

        // sum over all cells, adding the single‐cell path
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // include the length-1 path [grid[i][j]]
                dp[i][j][4] = (dp[i][j][4] + 1) % MOD;
                ans = (ans + dp[i][j][4]) % MOD;
            }
        }

        return (int)ans;
    }
};


