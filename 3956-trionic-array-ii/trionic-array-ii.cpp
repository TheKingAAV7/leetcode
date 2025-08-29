#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll LLONG_MIN_VAL = LLONG_MIN;
const ll LLONG_MAX_VAL = LLONG_MAX;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pref(n + 1, LLONG_MIN_VAL);
        vector<ll> suff(n + 1, LLONG_MIN_VAL);

        ll ans = LLONG_MIN_VAL;
        ll prev = LLONG_MIN_VAL;
        int cnt = 0;
        ll sm = 0;
        for (int i = 0; i < n; i++) {
            if (prev == LLONG_MIN_VAL) {
                prev = nums[i];
                sm = nums[i];
                cnt = 1;
            } else if (nums[i] > prev) {
                sm += nums[i];
                cnt += 1;
                if (cnt >= 3) {
                    if (sm > 0) {
                        pref[i] = max(sm, 0ll + nums[i - 1] + nums[i]);
                    } else {
                        pref[i] = max(sm, 0ll + nums[i - 1] + nums[i]);
                    }
                    sm=max(sm,0ll + nums[i - 1] + nums[i]);
                } else {
                    pref[i] = sm;
                }
                prev = nums[i];
            } else {
                prev = nums[i];
                sm = nums[i];
                cnt = 1;
            }
        }

        ans = LLONG_MIN_VAL;
        prev = LLONG_MIN_VAL;
        cnt = 0;
        sm = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (prev == LLONG_MIN_VAL) {
                prev = nums[i];
                sm = nums[i];
                cnt = 1;
            } else if (nums[i] < prev) {
                sm += nums[i];
                cnt += 1;
                if (cnt >= 3) {
                    if (sm > 0) {
                        suff[i] = max(sm, 0ll + nums[i] + nums[i + 1]);
                    } else {
                        suff[i] = max(sm, 0ll + nums[i] + nums[i + 1]);
                    }
                    sm=max(sm, 0ll + nums[i] + nums[i + 1]);
                } else {
                    suff[i] = sm;
                }
                prev = nums[i];
            } else {
                prev = nums[i];
                sm = nums[i];
                cnt = 1;
            }
        }

        // for i in pref: print(i, end=" ")
        // print()
        // for i in suff: print(i, end=" ")
        // print()

        prev = LLONG_MIN_VAL;
        ll dsm = 0;
        int lef = -1;

        // for(ll i:pref) cout<<i<<" ";
        // cout<<endl;
        // for(ll i:suff) cout<<i<<" ";
        // cout<<endl; 
        for (int i = 1; i < n - 1; i++) {
            if (prev == LLONG_MIN_VAL) {
                prev = nums[i];
                dsm = nums[i];
                lef = i;
            } else if (nums[i] < prev) {
                dsm += nums[i];

                // check lef sm 
                ll lefsm = pref[lef];
                ll rigsm = suff[i];
              //  cout<<i<<" "<<dsm<<" "<<lefsm<<" "<<rigsm<<endl;

                if (lefsm != LLONG_MIN_VAL && rigsm != LLONG_MIN_VAL) {
                    ll candidate = lefsm + rigsm + dsm - nums[i] - nums[lef];
                    ans = max(ans, candidate);
                }

                prev = nums[i];
            } else {
                prev = nums[i];
                dsm = nums[i];
                lef = i;
            }
        }

        // if ans == LLONG_MIN: print("YEs")
        return (ans == LLONG_MIN_VAL ? -1 : ans);
    }
};
