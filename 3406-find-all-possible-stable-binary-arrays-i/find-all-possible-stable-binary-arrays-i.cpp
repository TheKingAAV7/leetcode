int mod=1e9+7;
class Solution {
public:
   
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>>dp(zero+1,vector<vector<int>>(one+1,vector<int>(2,0)));

        // memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        dp[0][0][1]=1;
    
        for(int i=0;i<=zero;i++){
            for(int j=0;j<=one;j++){
                 if(i==0 and j==0) continue;
                for(int k=0;k<=1;k++){
                    if(k==0){
                        int sz= min(i,limit);
                        for(int l=1;l<=sz;l++){
                            if(i-l>=0)
                            dp[i][j][k]=(dp[i][j][k]+dp[i-l][j][1])%mod;
                        }
                    }
                    else{
                        int sz= min(j,limit);
                        for(int l=1;l<=sz;l++){
                            if(j-l>=0)
                            dp[i][j][k]=(dp[i][j][k]+dp[i][j-l][0])%mod;
                        }
                    }
                }
            }
        }

        
        return (dp[zero][one][0] + dp[zero][one][1])%mod;

    }
};