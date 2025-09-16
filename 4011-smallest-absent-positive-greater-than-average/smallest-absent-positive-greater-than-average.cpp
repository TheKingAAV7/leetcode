class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n=nums.size();
        double sm=0;
        for(int i:nums) sm+=(i);
        
        int avg=floor(sm/(n*1.0)) + 1;
        if(avg<=0) avg=1;
        
        
      
        while(true){
            bool pres=false;
            for(int i=0;i<n;i++){
                if(nums[i]==avg){
                    pres=true;
                    break;
                }
            }
            if(!pres)  return avg;
            avg+=1;
        }
        return -1;
    }
};