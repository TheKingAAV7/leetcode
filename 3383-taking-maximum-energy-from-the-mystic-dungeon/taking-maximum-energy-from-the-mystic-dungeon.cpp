class Solution {
public:
    int maximumEnergy(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,INT_MIN);
        for(int i=0;i<n;i++){
            if(i-k>=0){
                dp[i]=arr[i]+dp[i-k];
            }

            dp[i]=max(dp[i],arr[i]);
        }
        // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        // cout<<endl;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int left=(n-i);
            int cur=i;
            int far=(left)/k;
            cur+=(far)*k;
            //cout<<i<<" "<<cur-1<<endl;
            if(cur-1<n)
            maxi=max(maxi,dp[cur-1]);
        }
        // if(maxi==0){
        //  //return *max_element(arr.begin(),arr.end());
        //  int ans=INT_MIN;
        //  for(int i=0;i<k;i++){
        //     ans=max(ans,arr[n-i-1]);
        //  }
        //  return ans;
        // }

        return maxi;
    }
};