class Solution {
public:
    bool prime(int n){
        if(n<2) return false;
        if(n==2) return true;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int nonSpecialCount(int l, int r) {
        int lef=sqrt(l);
        int rig=1+sqrt(r);
        int cnt=0;
        int total=r-l+1;
        for(int i=lef;i<=rig;i++){
                if(prime(i)){
                    int sq=i*i;
                    if(sq>=l and sq<=r) cnt++;
                }
        }
        return total-cnt;
    }
};