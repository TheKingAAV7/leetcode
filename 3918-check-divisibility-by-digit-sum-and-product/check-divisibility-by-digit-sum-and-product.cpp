class Solution {
public:
    bool checkDivisibility(int n) {
        int sm=0;
        int prod=1;
        int N=n;
        while(n>0){
            int lst= n%10;
            sm+=lst;
            prod*=lst;
            n/=10;
        }
        // cout<<sm<<" "<<prod<<endl;
        return ((N%(prod+sm))==0);
    }
};