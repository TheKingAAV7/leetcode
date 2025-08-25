#define ll long long
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        ll od=n*n;
        ll ev=n*(n+1);
        return gcd(od,ev);
    }
};