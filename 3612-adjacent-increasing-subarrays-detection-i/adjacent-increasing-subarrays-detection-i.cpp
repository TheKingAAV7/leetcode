class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
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