class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        if(arr[0]>0){
            dp[0][0]=dp[0][1]=arr[0];
        }
        
        for(int i=1;i<n;i++){
            
             dp[i][0]=max({dp[i-1][0]+arr[i],
                           arr[i],dp[i][0]});
            
            //   if(arr[i]<0)
                dp[i][1]=max({dp[i-1][0],dp[i-1][1]+arr[i],arr[i],0});
            
        }
        int maxi=0;
        for(int i=0;i<n;i++){
           maxi=max({maxi,dp[i][0],dp[i][1]});
           //cout<<max(dp[i][0],dp[i][1])<<" ";
        }
        

        if(maxi==0) return *max_element(arr.begin(),arr.end());
        return maxi;
    }
};