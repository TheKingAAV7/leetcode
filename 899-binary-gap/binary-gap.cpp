class Solution {
public:
    int binaryGap(int n) {
        int ans=0;
        for(int i=0;i<31;i++){
            if(((n>>i)&1) == 0) continue; 
            for(int j=i+1;j<31;j++){
                if( ((n>>j)&1)) {
                    ans=max(ans,j-i);
                    break;
                }
            }
        }
        return ans;
    }
};