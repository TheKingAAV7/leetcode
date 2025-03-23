class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {

        long long tot_weight = n*n*w;
        int ans;
        if(tot_weight >= maxWeight){
            ans = maxWeight/w;
        }
        else{
            ans = n*n;
        }
        return ans;

        
    }
};