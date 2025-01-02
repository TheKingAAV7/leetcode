class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int low=1,high=n;
        auto f=[&](int k)->bool{
            int sm=0;
            for(int i=0;i<k;i++){
                sm+=nums[i];
            }
            if(sm>=target) return true;
            for(int i=k;i<n;i++){
                sm+=nums[i];
                sm-=nums[i-k];
                if(sm>=target) return true;
            }
            return false;

        };
        while(low<=high){
            int mid=(low+high)>>1;
            if(f(mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};