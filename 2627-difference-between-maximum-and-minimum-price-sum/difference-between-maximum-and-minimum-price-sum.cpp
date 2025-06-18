#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        // Save n and price
        this->n = n;
        this->price = price;
        // Build adjacency list
        adj.assign(n, {});
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // Prepare data structures:
        // idx[u] maps neighbor value -> index in adj[u]
        idx.assign(n, unordered_map<int,int>());
        // dpVal[u][i] corresponds to dp[u][ adj[u][i] ]
        dpVal.assign(n, vector<long long>());

        for (int u = 0; u < n; ++u) {
            int sz = adj[u].size();
            dpVal[u].assign(sz, 0LL);
            for (int i = 0; i < sz; ++i) {
                idx[u][ adj[u][i] ] = i;
            }
        }

        // Phase A: post-order DFS to fill dp[u][v] for edges where u is "parent" in this DFS
        dfsA(0, -1);
        // Phase B: pre-order DFS to fill dp[v][u] for the opposite directions
        dfsB(0, -1);

        // Finally compute answer: for each node x, 
        // bestBranch = max over neighbors y of dp[x][y]; 
        // cost at x = bestBranch (since maxPath = price[x] + bestBranch, minPath = price[x], difference = bestBranch).
        long long ans = 0;
        for (int u = 0; u < n; ++u) {
            long long bestBranch = 0;
            int deg = adj[u].size();
            for (int i = 0; i < deg; ++i) {
                bestBranch = max(bestBranch, dpVal[u][i]);
            }
            ans = max(ans, bestBranch);
        }
        return ans;
    }

private:
    int n;
    vector<int> price;
    vector<vector<int>> adj;
    vector<unordered_map<int,int>> idx;
    vector<vector<long long>> dpVal;

    // Phase A: post-order DFS: for each edge u->v where v != parent, compute dp[u][v]
    void dfsA(int u, int p) {
        // Recurse into children first
        for (int v : adj[u]) {
            if (v == p) continue;
            dfsA(v, u);
        }
        // Now fill dp[u][v] for each child v
        for (int v : adj[u]) {
            if (v == p) continue;
            // We want dp[u][v] = price[v] + max_{w in adj[v], w != u} dp[v][w], or price[v] if no such w
            long long bestChild = 0;
            for (int w : adj[v]) {
                if (w == u) continue;
                int idx_v_w = idx[v][w];
                bestChild = max(bestChild, dpVal[v][idx_v_w]);
            }
            int idx_u_v = idx[u][v];
            dpVal[u][idx_u_v] = (long long)price[v] + bestChild;
        }
        // Note: dp[u][index_of(p)] is left as 0 for now; will be set in Phase B when processing parent side.
    }

    // Phase B: pre-order DFS: for each edge u->v, compute dp[v][u] using values dp[u][*]
    void dfsB(int u, int p) {
        // Among all neighbors k of u, collect dp[u][k] to find top two max values
        long long mx1 = 0, mx2 = 0;
        for (int v : adj[u]) {
            int idx_u_v = idx[u][v];
            long long val = dpVal[u][idx_u_v];
            if (val >= mx1) {
                mx2 = mx1;
                mx1 = val;
            } else if (val > mx2) {
                mx2 = val;
            }
        }
        // For each neighbor v != p, set dp[v][u] = price[u] + best among dp[u][k] for k != v
        for (int v : adj[u]) {
            if (v == p) continue;
            int idx_u_v = idx[u][v];
            long long cur = dpVal[u][idx_u_v];
            long long use = (cur == mx1 ? mx2 : mx1);
            int idx_v_u = idx[v][u];
            dpVal[v][idx_v_u] = (long long)price[u] + use;
            // Recurse
            dfsB(v, u);
        }
    }
};
