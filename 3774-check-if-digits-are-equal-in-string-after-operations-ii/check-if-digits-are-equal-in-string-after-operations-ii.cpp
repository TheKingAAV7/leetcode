#include <bits/stdc++.h>
using namespace std;
 
// Factorizes x by removing all factors of 2 and 5.
// Returns in cnt2 and cnt5 the number of factors of 2 and 5,
// and in 'non' the remaining part (which will be coprime with 10).
void factorize(int x, int &cnt2, int &cnt5, int &non){
    cnt2 = 0; cnt5 = 0;
    while(x % 2 == 0){
        cnt2++;
        x /= 2;
    }
    while(x % 5 == 0){
        cnt5++;
        x /= 5;
    }
    non = x % 10;
}
 
// Modular inverse modulo 10 for numbers that are coprime with 10.
// (The only possibilities here are 1, 3, 7, or 9.)
int modInv(int x){
    if(x == 1) return 1;
    if(x == 3) return 7; // 3*7 = 21 ≡ 1 (mod 10)
    if(x == 7) return 3; // 7*3 = 21 ≡ 1 (mod 10)
    if(x == 9) return 9; // 9*9 = 81 ≡ 1 (mod 10)
    return -1; // should not happen
}
 
// Given our representation of a coefficient as (non, exp2, exp5),
// compute its value mod 10.
int getCoeffValue(int non, int exp2, int exp5){
    // If both exp2 and exp5 are positive then a factor 10 divides the number.
    if(exp2 > 0 && exp5 > 0)
        return 0;
    int res = non % 10;
    if(exp2 > 0){
        // 2^k mod 10 for k>=1 cycles as: 2, 4, 8, 6.
        int cycle[4] = {2, 4, 8, 6};
        int power = cycle[(exp2 - 1) % 4];
        res = (res * power) % 10;
    }
    else if(exp5 > 0){
        // For any k>=1, 5^k mod 10 = 5.
        res = (res * 5) % 10;
    }
    return res % 10;
}
 
class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        // There are n-1 coefficients (row "n-2") indexed 0..(n-2):
        //   F0 = Σ (coeff[j] * d[j]), for j = 0..n-2
        //   F1 = Σ (coeff[j] * d[j+1]), for j = 0..n-2
        int N = n - 2;
 
        // Represent the current coefficient in our recurrence:
        // We'll store: nonPart (the part coprime with 10),
        // and the counts exp2 and exp5.
        int nonPart = 1;  // coefficient[0] is 1
        int exp2 = 0, exp5 = 0;
 
        // The first coefficient (j = 0) is 1.
        int coeff = getCoeffValue(nonPart, exp2, exp5);  // should be 1
        int F0 = (coeff * (s[0]-'0')) % 10;
        int F1 = (coeff * (s[1]-'0')) % 10;
 
        // Compute coefficients for j = 1 to j = N.
        // (There are N+1 coefficients in total, with indices 0..N.)
        for (int j = 0; j < N; j++){
            // Recurrence: coeff[j+1] = coeff[j] * (N - j) / (j+1)
            int numerator = N - j;
            int denominator = j + 1;
 
            int num2, num5, numNon;
            factorize(numerator, num2, num5, numNon);
 
            int den2, den5, denNon;
            factorize(denominator, den2, den5, denNon);
 
            // Update the non-coprime part:
            nonPart = (nonPart * (numNon % 10)) % 10;
            int invDen = modInv(denNon);  // denNon is coprime with 10
            nonPart = (nonPart * invDen) % 10;
 
            // Update exponent counts:
            exp2 = exp2 + num2 - den2;
            exp5 = exp5 + num5 - den5;
 
            int curCoeff = getCoeffValue(nonPart, exp2, exp5);
 
            int idx = j + 1;
            F0 = (F0 + curCoeff * (s[idx]-'0')) % 10;
            F1 = (F1 + curCoeff * (s[idx+1]-'0')) % 10;
        }
 
        return F0 == F1;
    }
};
 
