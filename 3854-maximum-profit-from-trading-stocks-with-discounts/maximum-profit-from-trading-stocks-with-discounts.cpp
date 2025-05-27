#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node,
             const vector<vector<int>>& adj,
             const vector<int>& pres,
             const vector<int>& fut,
             vector<vector<vector<long long>>>& dp,
             int budget,
             vector<int>& vis,
             const vector<int>& deg) {
        if (vis[node]) return;
        vis[node] = 1;
        // process children
        for (int c : adj[node]) {
            if (!vis[c]) dfs(c, adj, pres, fut, dp, budget, vis, deg);
        }
        // f[state][cost] = best from children
        vector<vector<long long>> f(3, vector<long long>(budget+1, LLONG_MIN/2));
        for (int s = 0; s < 3; ++s) f[s][0] = 0;
        // merge each child
        for (int c : adj[node]) {
            for (int s = 0; s < 3; ++s) {
                vector<long long> best(budget+1, LLONG_MIN/2);
                for (int k = 0; k <= budget; ++k) {
                    long long val = max(dp[c][k][0], dp[c][k][1]);
                    if (s > 0) val = max(val, dp[c][k][2]);
                    best[k] = val;
                }
                // knapsack merge
                vector<long long> ndp(budget+1, LLONG_MIN/2);
                for (int x = 0; x <= budget; ++x) {
                    for (int k = 0; k <= x; ++k) {
                        ndp[x] = max(ndp[x], f[s][x-k] + best[k]);
                    }
                }
                f[s].swap(ndp);
            }
        }
        // fill dp for node
        for (int x = 0; x <= budget; ++x) {
            // not buy
            dp[node][x][0] = f[0][x];
            // buy full
            if (x >= pres[node-1]) {
                long long gain = fut[node-1] - pres[node-1];
                dp[node][x][1] = f[1][x - pres[node-1]] + gain;
            }
            // buy half if boss bought
            if (deg[node] > 0 && x >= pres[node-1]/2) {
                long long gain = fut[node-1] - (pres[node-1]/2);
                dp[node][x][2] = f[2][x - pres[node-1]/2] + gain;
            }
        }
    }
public:
    int maxProfit(int n,
                  vector<int>& present,
                  vector<int>& future,
                  vector<vector<int>>& edges,
                  int budget) {
        vector<vector<vector<long long>>> dp(n+1,
            vector<vector<long long>>(budget+1, vector<long long>(3, LLONG_MIN/2)));
        vector<int> deg(n+1);
        vector<vector<int>> adj(n+1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            deg[e[1]]++;
        }
        vector<int> vis(n+1);
        dfs(1, adj, present, future, dp, budget, vis, deg);
        // answer is root states
        long long ans = 0;
        for (int s = 0; s < 3; ++s)
            for (int x = 0; x <= budget; ++x)
                ans = max(ans, dp[1][x][s]);
        return (int)ans;
    }
};

// usage in main omitted
