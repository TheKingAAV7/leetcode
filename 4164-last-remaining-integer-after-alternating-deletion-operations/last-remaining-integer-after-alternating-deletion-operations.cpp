#define ll long long
class Solution {
public:
    long long lastInteger(long long n) {
        // 1 2 3 4 5 6 7 8 9 10 11
        /*
         3 7
         1 3 5 7 9 11
          2 4 6 8 10
              1 5 9
              3
             
        
        first we destroy all evens.

        now, if n is odd
        
        1 2 3
        */
        ll strt=1;
        ll end=n;
        ll step=2;
        ll prevstep=1;
        bool lef=true;
        ll rem=n;
        while(rem>1){
            if(lef){
                ll destrt= strt+ step/2;
                if(destrt%step==end%step){
                    end=end- step/2;
                }
            }
            else{
                ll destrt=end-step/2;
                if(destrt%step==strt%step){
                    strt=strt+ step/2;
                }
            }
            

            step*=2;
            rem=rem-rem/2;
            lef=!lef;
        }
        return strt;
        
        
    }
};