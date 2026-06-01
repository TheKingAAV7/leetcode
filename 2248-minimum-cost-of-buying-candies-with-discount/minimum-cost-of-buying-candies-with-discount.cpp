class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n= cost.size();
        int sz= (n+1)/2;
        int sm=0;
        sort(cost.begin(),cost.end());
        
        int pos=n-1;
        while(pos>=0){
            sm+=cost[pos];
            pos--;
            if(pos>=0){
                sm+=cost[pos];
                pos-=2;

            }
        }

        return sm;
    }
};