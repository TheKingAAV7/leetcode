class Solution {
public:
    int maxBalancedShipments(vector<int>& wt) {
        int n=wt.size();
        int maxi=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(wt[i]<maxi){
                cnt++;
                maxi=-1;
            }
            else{
                maxi=max(maxi,wt[i]);
            }
        }
        return cnt;
        
    }
};