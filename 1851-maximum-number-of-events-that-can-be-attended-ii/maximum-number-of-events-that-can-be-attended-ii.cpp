class Solution {
public:
    int maxValue(vector<vector<int>>& ev, int K) {
        int n=ev.size();
        vector<vector<int>>dp(n+1,vector<int>(K+1,0));
        sort(ev.begin(),ev.end());
        // for(auto it:ev){
        //     cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        // }
       // cout<<endl;
        vector<int>tmp(n,0);
        for(int k=1;k<=K;k++){
            dp[n-1][k]=ev[n-1][2];
           
        }
        tmp[n-1]=ev.back()[0];
        for(int i=n-2;i>=0;i--){
            for(int k=1;k<=K;k++){
               // ntake
               dp[i][k]=max(dp[i][k],dp[i+1][k]);
               //take
               int st=ev[i][0];
               int et=ev[i][1];
               int val=ev[i][2];
                   auto it = upper_bound(ev.begin() + i, ev.end(), et,
        [](int value, const vector<int>& vec) {
            return value < vec[0];
        }
    );
                int idx=it-ev.begin();
               if(idx<n){
                dp[i][k]=max(dp[i][k],val+dp[idx][k-1]);
               }
               else dp[i][k]=max(dp[i][k],val);
            }
            tmp[i]=ev[i][0];
        }
        
        return dp[0][K];
        
    }
};