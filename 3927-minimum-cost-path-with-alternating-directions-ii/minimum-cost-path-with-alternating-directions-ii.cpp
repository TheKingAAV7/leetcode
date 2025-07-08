#define ll long long
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& wc) {
        ll inf=LLONG_MAX;
        vector<vector<ll>>dp(m,vector<ll>(n,inf));
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+ (i+1);
             dp[i][0]+=wc[i][0];
        }
        for(int j=1;j<n;j++){
            dp[0][j]= dp[0][j-1]+(j+1);
             dp[0][j]+=wc[0][j];
        }
        
        //cout<<n<<" "<<m<<endl;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
               
               
                    ll def=wc[i][j];
                    ll a=dp[i-1][j] + (i+1)*(j+1)*1ll + def;
                    ll b= dp[i][j-1] + (i+1)*(j+1)*1ll + def;
                    dp[i][j]=min({dp[i][j],a,b});
                
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        
        return dp[m-1][n-1]-wc[m-1][n-1];
    
    }
};