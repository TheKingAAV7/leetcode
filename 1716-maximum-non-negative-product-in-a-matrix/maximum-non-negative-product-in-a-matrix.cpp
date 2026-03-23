#define ll long long
class Solution {
public:
ll MOD=1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {

        // just maintain the smallest and highest product

        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<array<ll,2>>>dp(n,vector<array<ll,2>>(m,{LLONG_MAX,LLONG_MIN}));
        dp[0][0]={grid[0][0],grid[0][0]};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0) continue;
                ll uplo,uphi,leflo,lefhi;
                uplo=leflo=LLONG_MAX;
                uphi=lefhi=LLONG_MIN;
                if(i-1>=0){
                if(dp[i-1][j][0]!=LLONG_MAX and dp[i-1][j][1]!=LLONG_MIN and dp[i-1][j][0]!=LLONG_MIN and dp[i-1][j][1]!=LLONG_MAX)
                uplo= min({uplo,1ll*grid[i][j]*dp[i-1][j][0],1ll*grid[i][j]*dp[i-1][j][1]});
                if(dp[i-1][j][1]!=LLONG_MIN and dp[i-1][j][0]!=LLONG_MAX and dp[i-1][j][1]!=LLONG_MAX and dp[i-1][j][0]!=LLONG_MIN)
                uphi= max({uphi,1ll*grid[i][j]*dp[i-1][j][0],1ll*grid[i][j]*dp[i-1][j][1]});
                }
                if(j-1>=0){
                if(dp[i][j-1][0]!=LLONG_MAX and dp[i][j-1][1]!=LLONG_MIN and dp[i][j-1][0]!=LLONG_MIN and dp[i][j-1][1]!=LLONG_MAX){
                // cout<<dp[i][j-1][0]<<" "<<dp[i][j-1][1]<<endl;
                leflo=min({leflo,1ll*grid[i][j]*dp[i][j-1][0],1ll*grid[i][j]*dp[i][j-1][1]});
                }
                if(dp[i][j-1][1]!=LLONG_MIN and dp[i][j-1][0]!=LLONG_MAX and dp[i][j-1][1]!=LLONG_MAX and dp[i][j-1][0]!=LLONG_MIN )
                lefhi=max({lefhi,1ll*grid[i][j]*dp[i][j-1][0],1ll*grid[i][j]*dp[i][j-1][1]});
                }
                // if(i==0 and j==1) cout<<uplo<<" "<<uphi <<" "<<leflo<<" "<<lefhi<<endl;
                dp[i][j][0]= min(leflo,uplo);
                dp[i][j][1]= max(uphi,lefhi);
            }

        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++) cout<<"( "<<dp[i][j][0]<<" , "<<dp[i][j][1]<<" ) ";
        //     cout<<endl;
        // }
    ll ans= max(dp[n-1][m-1][1],dp[n-1][m-1][0]);
    if(ans<0) return -1;
    return ans%MOD;
    }
};