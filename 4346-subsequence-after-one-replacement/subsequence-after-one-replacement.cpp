class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n > m) return false;

        int cnt = 0;
        int lastMatch = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + lastMatch; j <= m - (n - i); j++) {
                if (s[i] == t[j]) {
                    if (i != j)
                        lastMatch = j;
                    cnt++;
                    break;
                }
            }
        }

        return cnt >= n - 1;
    }
};