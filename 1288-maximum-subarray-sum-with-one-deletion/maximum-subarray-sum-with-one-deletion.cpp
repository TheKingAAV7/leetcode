class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        if(arr[0]>0){
            dp[0][0]=arr[0];
            dp[0][1]=arr[0];
        }
        for(int i=1;i<n;i++){
            dp[i][0]=max({dp[i][0],dp[i-1][0]+arr[i],arr[i]});
            dp[i][1]=max({dp[i][1],dp[i-1][0],dp[i-1][1]+arr[i]});
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++) maxi=max(dp[i][j],maxi);
        }
        if(maxi==0) return *max_element(arr.begin(),arr.end());
        return maxi;
    }
};