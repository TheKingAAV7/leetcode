class Solution {
public:
    int MOD=1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& mat) {
        /*
        dp[i][j][x]

        e 2 3
        2 x 2
        1 2 s

        */
        int n= mat.size();
        int m= mat[0].size();
        int mx= (n+m)*9+1 ;
        int dp[n][m][mx];
        fill(&dp[0][0][0], &dp[0][0][0]+(n*m*mx),0);
        dp[n-1][m-1][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if((i==n-1 and j==m-1) || mat[i][j]=='X') continue;
                int val = 0;
                if(isdigit(mat[i][j]))
                    val = mat[i][j]-'0';

                for(int k=0;k<mx;k++){
                    if((k-val)<0) continue;
                    if(i+1<n)
                    dp[i][j][k]=(dp[i][j][k]+dp[i+1][j][k-(val)])%MOD;
                    if(j+1<m)
                    dp[i][j][k]=(dp[i][j][k]+dp[i][j+1][k-(val)])%MOD;
                    if(i+1<n and j+1<m)
                    dp[i][j][k]=(dp[i][j][k]+dp[i+1][j+1][k-(val)])%MOD;
                    // if(i==1 and j==2 and k==2) cout<<dp[i][j][k]<<endl;
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<" ( "<<i<<" "<<j<<" )-> ";
        //         for(int k=0;k<mx;k++) cout<<dp[i][j][k]<<" ";
        //         cout<<endl;
        //     }
        // }

        for(int i=mx-1;i>=0;i--){
            // cout<<dp[0][0][0]<<endl;
            if(dp[0][0][i]) return {i,dp[0][0][i]};
        }
        return {0,0};
    }
};