class Solution {
public:
    int maxBottlesDrunk(int nB, int nE) {
        int ans=nB;
        int empty=nB;
        int full=0;
        while((full+empty)>=nE){
            // cout<<full<<" "<<empty<<" "<<nE<<" "<<ans<<endl;
            if(empty>=nE){
                empty-=nE;
                nE++;
                full++;
            }
            else{
                empty+=full;
                ans+=full;
                full=0;
                empty-=nE;
                nE++;
                full++;
            }
            
        }
        ans+=full;
        return ans;
    }
};