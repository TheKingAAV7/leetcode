class Solution {
public:
    int lastRemaining(int n) {
       bool lef=true;
       int rem=n;
       int step=1;
       int head=1;
       while(rem>1){
        if(lef or rem%2==1){
            head=head+step;
        }
        rem/=2;
        step*=2;
        lef=!lef;
       }
       return head;
    }
};