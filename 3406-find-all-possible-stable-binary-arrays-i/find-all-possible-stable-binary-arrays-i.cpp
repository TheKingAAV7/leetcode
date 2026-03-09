
#define ll long long
class Solution {
public:
/*

Each subarray of size >limit must contain both 0 and 1

for the first subarray [0,limit] we must get a subarray which contains
both 0 and 1s => for all the other subarrays, we don't care whatever value 
we put

limit=2;
0 01 0 01
4
0001000000000
0101000000000



a,b

if(abs(a-b)>k;)
dp[i][a][b]= dp[i+1]

*/
    int MOD= 1e9+7;

    int numberOfStableArrays(int zero, int one, int limit) {
        
        
        int dp[zero+1][one+1][3][limit+1];
        memset(dp,-1,sizeof(dp));

        // vector<vector<vector<vector<ll>>>>dp(zero+1,vector<vector<vector<ll>>>(one+1,vector<vector<ll>>(3,vector<ll>(limit+1,-1))));
        auto f=[&](auto &&self,int a, int b, int prev,int d)->ll{
            if(a==0 and b==0) return 1;
            int ans=0;
            int np= prev+1;
            if(dp[a][b][np][d]!=-1) return dp[a][b][np][d];
            
                // put one
                if(b-1>=0){
                int d1= (prev==1?d+1:1);
                if(d1<=limit)
                ans= (ans + self(self,a,b-1,1,d1))%MOD;
                }

                if(a-1>=0){
                int d2= (prev==0?d+1:1);
                if(d2<=limit) 
                ans= (ans + self(self,a-1,b,0,d2))%MOD;
                }

                return dp[a][b][np][d]=ans;
            
        };

        return f(f,zero,one,-1,0);
    }
};