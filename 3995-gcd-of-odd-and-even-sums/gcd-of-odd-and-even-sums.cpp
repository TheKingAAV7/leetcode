class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sm1= n*n;
        int sm2= n*(n+1);
        return gcd(sm1,sm2);
    }
};