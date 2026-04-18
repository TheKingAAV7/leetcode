class Solution {
public:
    int mirrorDistance(int n) {
        int num=0;
        int x=n;
        while(x>0){
            int lst= x%10;
            num=num*10+lst;
            x/=10;
        }
        return abs(n-num);
    }
};