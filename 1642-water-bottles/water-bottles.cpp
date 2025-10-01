class Solution {
public:
    int numWaterBottles(int bott, int exch) {
        int ans=bott;
        int tot=bott;
        while(tot>=exch){
            
            //ans+=(tot);
            ans+=(tot/exch);
            int empty=(tot/exch)+(tot%exch);
            tot=empty;
        }
        return ans;
        
    }
};