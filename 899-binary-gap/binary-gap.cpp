class Solution {
public:
    int binaryGap(int n) {
        int curpos=0;
        int prev=-1;
        int ans=0;
        while(n>0){
            if(n&1){
                if(prev!=-1)
                ans=max(ans,curpos-prev);
                prev=curpos;
            }
            curpos++;
            n>>=1;
        }
        return ans;
    }
};