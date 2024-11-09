class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=0;
        long long tmp = n-1;
        //    100
        //  10
        long long x1=x;
        long long bit=0;
        long long t;
        while(tmp>0 ){
            if(((x1>>bit) & 1)==0){
                if(tmp&1){
                     t= 1LL<<bit;
                     x1= x1|t;
                }
                tmp=tmp>>1;
            }
            bit++;
        }
        return x1;

    }
};