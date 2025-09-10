class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& lang,
                         vector<vector<int>>& fri) {
        int m = lang.size();
        vector<vector<int>> adj(m + 1);
        for (auto it : fri) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n + 1, 0);
        map<int, set<int>> mp;
        for (int i = 1; i <= m; i++) {
            for (auto it : lang[i - 1]) {
                mp[i].insert(it);
                vis[it] = 1;
            }
        }

        set<int> bad;
        for (auto& e : fri) {
            int u = e[0], v = e[1];
            bool share = false;
            for (int L : mp[u])
                if (mp[v].count(L)) {
                    share = true;
                    break;
                }
            if (!share) {
                bad.insert(u);
                bad.insert(v);
            }
        }
        if (bad.empty())
            return 0;

        fill(vis.begin(), vis.end(), 0);
        for (int u : bad)
            for (int L : mp[u])
                vis[L] = 1;

        int ans = m;
        for (int i = 1; i <= n; i++) {
            if (!vis[i])
                continue;
            int tans = 0;
            for (int u : bad) {
                if (mp[u].find(i) == mp[u].end())
                    ++tans;
            }

            //  cout<<i<<" "<<ans<<endl;
            ans = min(ans, tans);
        }
        return ans;

        return ans;
    }
};