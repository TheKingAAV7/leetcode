class Solution {
public:
    int differenceOfSums(int n, int m) {
        int no=n/m;
        int total=(n*(n+1))/2;
        int smm= no*(m+m+(no-1)*m)/2;
        int smn=total-smm;
        return smn-smm;
    }
};