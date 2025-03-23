#define ll long long 

class Solution {
public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &r : roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }
        vector<ll> d(n, LLONG_MAX);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        d[n-1] = 0;
        pq.push({0, n-1});
        while(!pq.empty()){
            auto [dist, u] = pq.top();
            pq.pop();
            if(dist > d[u]) continue;
            for(auto &[v, w] : adj[u]){
                if(dist + w < d[v]){
                    d[v] = dist + w;
                    pq.push({d[v], v});
                }
            }
        }
        vector<int> dp(n, -1);
        function<int(int)> dfs = [&](int u) -> int {
            if(u == n-1) return 1;
            if(dp[u] != -1) return dp[u];
            ll ways = 0;
            for(auto &[v, w] : adj[u]){
                if(d[u] == d[v] + w)
                    ways = (ways + dfs(v)) % mod;
            }
            return dp[u] = ways;
        };
        return dfs(0);
    }
};
