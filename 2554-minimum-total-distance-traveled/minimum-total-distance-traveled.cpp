class Solution {
private:
    long long f(int i, int j, vector<int>& robots, vector<vector<int>>& factories, 
                vector<vector<long long>>& dp) {
        if (i >= robots.size()) return 0;  // All robots assigned
        if (j >= factories.size()) return LONG_LONG_MAX;  // No more factories but robots remain
        
        if (dp[i][j] != -1) return dp[i][j];  // Return memoized result
        
        long long ans = LONG_LONG_MAX;
        
        // Try not using current factory
        long long skip = f(i, j + 1, robots, factories, dp);
        if (skip != LONG_LONG_MAX) {
            ans = skip;
        }
        
        // Try using current factory for current robot and subsequent robots
        int limit = factories[j][1];  // Get factory capacity
        long long cost = 0;
        // Try assigning k robots to current factory
        for (int k = 0; k < limit && i + k < robots.size(); k++) {
            cost += abs(robots[i + k] - factories[j][0]);  // Add distance cost
            long long next = f(i + k + 1, j + 1, robots, factories, dp);
            if (next != LONG_LONG_MAX) {
                ans = min(ans, cost + next);
            }
        }
        
        return dp[i][j] = ans;  // Memoize and return
    }

public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        // Initialize dp array with -1
        vector<vector<long long>> dp(robot.size(), 
                                   vector<long long>(factory.size(), -1));
        
        return f(0, 0, robot, factory, dp);
    }
};