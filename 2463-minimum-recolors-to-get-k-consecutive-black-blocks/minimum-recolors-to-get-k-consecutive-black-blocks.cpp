class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int w=0;
        int n=blocks.size();
        int ans=200;
        for(int i=0;i<k;i++){
            (blocks[i]=='W')? w++:w+=0;
        }
        ans=min(ans,w);
        for(int i=k;i<n;i++){
            (blocks[i-k]=='W')? w--:w-=0;
             (blocks[i]=='W')? w++:w+=0;
             ans=min(ans,w);
        }
        return ans;
    }
};