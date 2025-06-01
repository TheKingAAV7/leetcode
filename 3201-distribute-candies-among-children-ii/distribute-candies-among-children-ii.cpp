class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        ans += c(n + 2,2);
        ans -= c(n - limit + 1, 2) * 3;
        ans += c(n - 2 * limit, 2) * 3;
        ans -= c(n - 3 * limit - 1, 2);
        return ans;
    }
   
    long long c(int n, int m) {
        if (n < m) return 0;
        return (long long)n * (n - 1) / m / (m - 1);
    }
};