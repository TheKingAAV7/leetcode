class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long ans=LLONG_MIN;
        int n=nums.size();
        vector<long long>pmx(n,LLONG_MIN),pmin(n,LLONG_MAX);

        long long maxi=LLONG_MIN,mini=LLONG_MAX;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,nums[i]*1LL);
            mini=min(mini,nums[i]*1LL);
            pmx[i]=maxi;
            pmin[i]=mini;
        }
        for(int i=0;i<n;i++){
            int nxt=i+m-1;
            if(nxt<n){
                long long tmp1=pmx[nxt]*nums[i];
                long long tmp2=pmin[nxt]*nums[i];
                ans=max({ans,tmp1,tmp2});
            }
        }
        return ans;
    }

};