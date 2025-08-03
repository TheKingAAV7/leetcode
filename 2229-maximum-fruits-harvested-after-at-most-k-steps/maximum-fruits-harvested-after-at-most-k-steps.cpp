#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& ft, int sp, int k) {
        int n = ft.size(), sm = 0, ans = 0;
        vector<int> pref(n, 0);
        for (int i = 0; i < n; i++) {
            sm += ft[i][1];
            pref[i] = sm;
        }

        // ─── HANDLE THE 4 “EXTREMES” ────────────────────────────────────────
        // 1) Purely left:
        {
            int i = lower_bound(ft.begin(), ft.end(), sp - k,
                                [](auto &A, int v){ return A[0] < v; }) - ft.begin();
            int j = upper_bound(ft.begin(), ft.end(), sp,
                                [](int v, auto &A){ return v < A[0]; })
                    - ft.begin() - 1;
            if (i < n && j >= i) {
                ans = max(ans, pref[j] - (i>0 ? pref[i-1] : 0));
            }
        }
        // 2) Purely right:
        {
            int i = lower_bound(ft.begin(), ft.end(), sp,
                                [](auto &A, int v){ return A[0] < v; }) - ft.begin();
            int j = upper_bound(ft.begin(), ft.end(), sp + k,
                                [](int v, auto &A){ return v < A[0]; })
                    - ft.begin() - 1;
            if (i < n && j >= i) {
                ans = max(ans, pref[j] - (i>0 ? pref[i-1] : 0));
            }
        }
        // 3) Go right first, then left:
        for (int i = 0; i < n; i++) {
            int posR = ft[i][0];
            if (posR < sp) continue;
            int d = posR - sp;
            if (d > k) break;
            // after going right to posR, you have rem = k - d steps to go left:
            int leftmost = 2*posR - k - sp;
            int a = lower_bound(ft.begin(), ft.end(), leftmost,
                                [](auto &A, int v){ return A[0] < v; }) - ft.begin();
            ans = max(ans, pref[i] - (a>0 ? pref[a-1] : 0));
        }
        // 4) Go left first, then right:
        for (int i = n - 1; i >= 0; i--) {
            int posL = ft[i][0];
            if (posL > sp) continue;
            int d = sp - posL;
            if (d > k) break;
            // after going left to posL, you have rem = k - d steps to go right:
            int rightmost = k + 2*posL - sp;
            int b = upper_bound(ft.begin(), ft.end(), rightmost,
                                [](int v, auto &A){ return v < A[0]; })
                    - ft.begin() - 1;
            ans = max(ans, (b>=0 ? pref[b] : 0) - (i>0 ? pref[i-1] : 0));
        }
        // ────────────────────────────────────────────────────────────────────

        // your original two-pointer window, unchanged:
      

        return ans;
    }
};
