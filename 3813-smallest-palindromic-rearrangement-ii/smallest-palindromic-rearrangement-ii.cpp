class Solution {
private:
    const long long INF = 1000000000000000000LL;

    long long combination(int n, int r) {
        if (r > n)
            return 0;
        if (r > n - r)
            r = n - r;
         long long res = 1;
    for (int i = 1; i <= r; i++) {
        int numerator = n - i + 1;
      
        if (res > INF / numerator) {
          
            return INF;
        }
        res = res * numerator;
       
        res /= i;
      
        if (res >= INF)
            return INF;
    }
    return res;
    }

    long long countp(const vector<int>& freq) {
        int rem = 0;
        for (int f : freq)
            rem += f;
        long long ways = 1;

        for (int f : freq) {
            if (f > 0) {
                long long ways_here = combination(rem, f);

                if (ways > INF / ways_here) {
                    ways = INF;
                } else {
                    ways *= ways_here;
                }
                rem -= f;
            }
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> mp(26, 0);
        for (char c : s)
            mp[c - 'a']++;
        string mid = "";
        vector<int> lef(26, 0);
        for (int i = 0; i < 26; i++) {
            if (mp[i] % 2) {
                mid = string(1, char('a' + i));
            }
            lef[i] = mp[i] / 2;
        }
        int halflen = 0;
        for (int i : lef)
            halflen += i;
        long long total = countp(lef);
        if (k > total)
            return "";
        string tmp = "";
        for (int pos = 0; pos < halflen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (lef[c] > 0) {
                    lef[c]--;
                    long long ways = countp(lef);
                    if (ways >= k) {
                        tmp.push_back('a' + c);
                        break;
                    } else {
                        k -= ways;
                        lef[c]++;
                    }
                }
            }
        }
        string tmp2 = tmp;
        reverse(tmp2.begin(), tmp2.end());
        string ans = tmp + mid + tmp2;
        return ans;
    }
};