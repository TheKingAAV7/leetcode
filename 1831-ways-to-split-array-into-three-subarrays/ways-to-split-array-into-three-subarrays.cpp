class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> pre(n,0);
           pre[0]=nums[0];
        for(int i=1;i<n;i++)
        pre[i]=pre[i-1]+nums[i];
        int mod=1e9+7;
        // 1 3 5 7 12 12 
        for(int i=0;i<n;i++)
        {
           int low=lower_bound(pre.begin()+i+1,pre.end(),2*pre[i])-pre.begin();//it will return min boundary if we have middle subarray sum equal to first sub array sum(we are checking 2*pre[i] because it is prefix sum and we do not have to conside first subarray sum i.e pre[i])
           int up=upper_bound(pre.begin()+i+1,pre.begin()+n-1,pre[i]+((pre[n-1]-pre[i])/2))-pre.begin();//max for second subarray will (remaing part)/2 
           ans+=(max(0,(up-low)))%mod;
           ans=ans%mod;
        }
      return ans;
    }
};