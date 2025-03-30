class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int req=0;
        int extra=0;
        int cur=0;
        int n=gas.size();
        int idx=-1;
        for(int i=0;i<n;i++){
            cur+=gas[i];
            if(cur<cost[i]){
                req+=(cost[i]-cur);
                cur=0;
                idx=-1;
                
            }
            else{
                if(idx==-1){
                idx=i;
                }
                extra=(cur-cost[i]);
                cur-=cost[i];
            }
        }
      //  cout<<req<<" "<<extra<<endl;
        
        return extra>=req?idx:-1;     
    }
};