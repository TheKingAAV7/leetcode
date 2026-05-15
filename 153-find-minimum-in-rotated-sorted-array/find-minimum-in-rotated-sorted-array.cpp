class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int lo=0,hi=n-1;
       
        while(lo<hi){
            int mid= (lo+hi)>>1;
            if(nums[mid]<nums[hi]){
                hi=mid;
            }
            else{
                lo=mid+1;
            }
        }

        return nums[lo];
    }
};