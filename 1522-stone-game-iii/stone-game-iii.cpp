class Solution {
public:
    string stoneGameIII(vector<int>& arr) {
        int n= arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n-1][0]=arr.back();
        dp[n-1][1]=-arr.back();

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==0){
                    dp[i][j]=INT_MIN;
                    // one 
                    dp[i][j]=max(dp[i][j],arr[i]+dp[i+1][1]);
                    // if(i==0) cout<<dp[i][j]<<endl;
                    // two
                    if(i+1<n)
                    dp[i][j]=max(dp[i][j],arr[i]+arr[i+1] + dp[i+2][1]);
                    // if(i==0) cout<<dp[i][j]<<endl;
                    // three
                    if(i+2<n)
                    dp[i][j]=max(dp[i][j],arr[i]+arr[i+1] + arr[i+2] + dp[i+3][1]);
                    // if(i==0) cout<<arr[i]+arr[i+1] + arr[i+2]<<endl;
                }
                else{
                    // one 
                    dp[i][j]=INT_MAX;
                    dp[i][j]=min(dp[i][j],-arr[i]+dp[i+1][0]);
                    // two
                    if(i+1<n)
                    dp[i][j]=min(dp[i][j],-arr[i]-arr[i+1] + dp[i+2][0]);
                    // three
                    if(i+2<n)
                    dp[i][j]=min(dp[i][j],-arr[i]-arr[i+1] - arr[i+2] + dp[i+3][0]);
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<2;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<dp[0][0]<<endl;
        if(dp[0][0]>0) return "Alice";
        else if(dp[0][0]<0) return "Bob";
        return "Tie";
        
    }
};