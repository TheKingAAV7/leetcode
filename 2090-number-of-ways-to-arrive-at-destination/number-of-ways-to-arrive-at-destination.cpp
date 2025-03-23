#define ll long long 

class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>> adj(n);
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<ll> dist(n, LLONG_MAX);
        vector<ll> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u])
                continue;
            for(auto &[v, w]: adj[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } else if(dist[u] + w == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};
