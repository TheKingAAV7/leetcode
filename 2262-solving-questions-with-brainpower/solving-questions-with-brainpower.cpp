#define ll long long

class Solution {
public:
    long long mostPoints(vector<vector<int>>& que) {
        int n = que.size();
        vector<ll> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = max(dp[i], dp[i + 1]);
            dp[i] = max(dp[i], que[i][0] + dp[min(i + que[i][1] + 1, n)]);
        }

        return dp[0];
    }
};