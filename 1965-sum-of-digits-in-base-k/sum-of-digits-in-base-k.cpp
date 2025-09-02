class Solution {
public:
    int sumBase(int n, int k) {
        int tmp=0;
        while(n>0){
            int po=0;
            while(pow(k,po)<=n){
                po++;
            }
            po--;
            int divis=pow(k,po);
           
            int req=n/divis;
            n-=(divis*req);
            tmp=tmp*10+req;
        }
      
        int sm=0;
        while(tmp){
            sm+=(tmp%10);
            tmp/=10;
        }
        return sm;
    }
};