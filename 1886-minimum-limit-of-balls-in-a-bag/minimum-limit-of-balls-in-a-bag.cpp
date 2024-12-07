class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        long long low=1,high=*max_element(nums.begin(),nums.end());
        auto f=[&](int k)->bool{
        long long op=0;
        
        for(int i: nums){
            if(i>k){
               if(k==0){
                op+=(i-1);
               }
               else
                op+=((i-1)/k);
            }
            
        }
        return op<=maxOperations;
        };
        int ans;
        while(low<=high){
            long long mid=(low+high)/2;
            if(f(mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};