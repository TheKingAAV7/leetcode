class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n);
        for(int i=0;i<n;i++){
            int m=arr[i].size();
            dp[i].resize(m);
        }
        for(int i=0;i<arr.back().size();i++){
            dp[n-1][i]=arr[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            int m=arr[i].size();
            for(int j=m-1;j>=0;j--){
                dp[i][j]=arr[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
        
    }
};