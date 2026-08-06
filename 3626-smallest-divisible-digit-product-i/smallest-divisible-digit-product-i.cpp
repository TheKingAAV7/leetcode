class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int x=n;x<=n+11;x++){
            int prod= 1;
            int tmp= x;
            while(tmp>0){
                prod*=(tmp%10);
                tmp/=10;
            }
            if(prod%t == 0) return x;
        }
        return -1;
    }
};