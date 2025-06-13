class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        auto f=[&](int mid)->bool{
            int cnt=0;
            for(int i=0;i<n-1;i++){
                if((nums[i+1]-nums[i])<=mid){
                    cnt++;
                    i++;
                }
            }
            return cnt>=p;
        };
        int lo=0,hi=nums.back()-nums[0];
        int ans=hi;
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(f(mid)) {
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
            
    }
};