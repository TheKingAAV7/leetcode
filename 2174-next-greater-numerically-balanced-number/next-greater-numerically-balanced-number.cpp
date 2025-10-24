
class Solution {
    bool balance(int n) {
        int cnt[10] = {};
        while (n) {
            if (n % 10 == 0) return false; 
            cnt[n % 10]++;
            n /= 10;
        }
        for (int i = 1; i < 10; ++i) {
            if (cnt[i] && cnt[i] != i) return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        while (true) {
            ++n;
            if (balance(n)) return n;
        }
    }
};