class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int k = queries.size();
        
        // Store original indices before sorting queries
        vector<int> pos(k);
        iota(pos.begin(), pos.end(), 0);
        sort(pos.begin(), pos.end(), [&](int a, int b) {
            return queries[a] < queries[b]; // Sort queries in ascending order
        });

        // Direction vectors for 4-way movement
        vector<int> row = {0, 0, 1, -1};
        vector<int> col = {1, -1, 0, 0};

        // Min-Heap (value, x, y)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;

        vector<int> ans(k, 0);
        int count = 0; // Number of nodes visited
        int prevValue = 0; // Last query value processed

        for (int i = 0; i < k; i++) {
            int q = queries[pos[i]];

            // Expand the min-heap while nodes have values < current query
            while (!pq.empty() && pq.top().first < q) {
                auto [val, cell] = pq.top();
                pq.pop();
                int x = cell.first, y = cell.second;

                count++; // New node visited

                // Expand in 4 directions
                for (int d = 0; d < 4; d++) {
                    int nx = x + row[d], ny = y + col[d];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        pq.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }

            ans[pos[i]] = count;
        }

        return ans;
    }
};
