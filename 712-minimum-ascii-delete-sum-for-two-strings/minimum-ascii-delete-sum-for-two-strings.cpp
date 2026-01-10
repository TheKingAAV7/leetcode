class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        int suff1[n+1];
        int suff2[m+1];
        int sm=0;
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        for(int i=n-1;i>=0;i--) {
            sm+=(int)(s1[i]);
            suff1[i]=sm;
        }
        sm=0;
        for(int i=m-1;i>=0;i--){
            sm+=(int)(s2[i]);
            suff2[i]=sm;
        }


      //  vector<vector<int>>dp(n,vector<int>(m,-1));
        function<int(int , int )>f=[&](int i, int j)->int{
            if(i>=n || j>=m){
                if(i>=n and j>=m) return 0;
                if(i>=n) return suff2[j];
                return suff1[i];
            }
            if(dp[i][j]!=-1) return dp[i][j];
            int ans=0;
            if(s1[i]==s2[j]) ans=   f(i+1,j+1);
            else{
                ans= min((int)(s1[i]) + f(i+1,j),(int)(s2[j])+f(i,j+1));
            }
            return dp[i][j]= ans;
        };
        return f(0,0);
    }
};