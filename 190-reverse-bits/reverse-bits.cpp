class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int b=0;b<32;b++){
            if((n>>b)&1){
                ans|=(1<<(32-b-1));
            }
        }
        return ans;
    }
};