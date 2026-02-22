class Solution {
public:
    int binaryGap(int n) {
        int prev=-1;
        int ans=0;
        for(int i=0;i<30;i++){
            // check if the ith bit set or not
            if(((n>>i)&1)==1){
                
                // this is a set bit
                // calculate the distance
                int distance;
                if(prev!=-1){
                distance= i-prev;
               // cout<<distance<<endl;
                ans=max(ans,distance);
                }
                prev=i;
            }
        }
        return ans;
    }
};