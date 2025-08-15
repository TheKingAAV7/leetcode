class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int total=floor(log2(1.0*n));
        int set=__builtin_popcount(n);
        
       // cout<<total<<endl;
        return set==1 and total%2==0;
    }
};