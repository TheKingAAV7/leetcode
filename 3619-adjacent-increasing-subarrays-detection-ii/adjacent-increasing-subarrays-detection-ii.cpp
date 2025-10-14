class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int lo=1,hi=n;
        int ans=lo;
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(f(nums,mid)){
                lo=mid+1;
                ans=mid;
            }
            else hi=mid-1;
        }
        return ans;

    }

     bool f(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>vis(n,0);
        int lef=0;
        int i=0;
        int prev=-1;
        while(i<n){
            
            if(nums[i]>prev){
                prev=nums[i];
                i++;
            }
            else{
                lef=i;
                prev=nums[lef];
                i++;
            }

            if(i-lef+1>k){
                vis[lef]=1;
                lef++;
            }
           
        }
        for(int i=0;i<n-k;i++){
            if(vis[i] and vis[i+k]) return true;
        }
        return 0;
    }
};

