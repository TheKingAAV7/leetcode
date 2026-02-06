class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans= n-1;

        for(int i=0;i<n;i++){
            long long  x=1ll * nums[i]*k;
            auto it= upper_bound(nums.begin(),nums.end(),x);
            int idx= it-nums.begin();
            int req= n-idx;
            //cout<<i<<" "<<req<<endl;
            ans=min(ans,i+req);
        }
        return ans;

    }
};