class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int sm=INT_MAX;
        for(int k=l;k<=r;k++){
            int tmp=0;
        for(int i=0;i<k;i++){
            tmp+=nums[i];
        }
            if(tmp>0){
                sm=min(tmp,sm);
            }
        for(int i=k;i<n;i++){
            tmp-=nums[i-k];
            tmp+=nums[i];
             if(tmp>0){
                sm=min(tmp,sm);
            }
        }

            
        }
        return sm==INT_MAX?-1:sm;
    }
};