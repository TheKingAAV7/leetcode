class Solution {
public:
    long long coloredCells(int n) {
        long long prev=1;
        if(n==1 ) return 1;
        if(n==2) return 5;
        long long cnt=1;
        for(int i=2;i<=n;i++){
            prev+=(4*cnt);
            cnt++;
        }
        return prev;
    }
};