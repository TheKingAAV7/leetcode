class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans;
        for(ans=0;n>0;n&=n-1){
            ans= -(ans+(n^(n-1)));
        }
        return abs(ans);
    }
};