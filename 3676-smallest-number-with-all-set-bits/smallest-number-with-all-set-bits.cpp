class Solution {
public:
    int smallestNumber(int n) {
        // count no. of bits and answer is (1<<(n+1))-1
        int cnt=0;
        while(n>0){
            cnt++;
            n>>=1;
        }
        return (1<<(cnt))-1;
    }
};