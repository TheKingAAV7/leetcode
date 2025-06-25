class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long ans=LLONG_MIN;
        int n=nums.size();
        long long maxi=INT_MIN;
        vector<long long>v1(n,0),v2(n,0);
        long long mini=INT_MAX;
        for(int i=n-1;i>=0;i--){
            maxi=max(nums[i]*1ll,maxi);
            mini=min(mini,nums[i]*1ll);
            v1[i]=maxi;
            v2[i]=mini;
        }
        for(int i=0;i<n;i++){
            if(i+m-1<n){
              
                long long tmp=nums[i]*v1[i+m-1]*1ll;
                long long tmp1=nums[i]*v2[i+m-1]*1ll;
                ans=max({ans,tmp1,tmp});
            }
        }
        return ans;

    }
};