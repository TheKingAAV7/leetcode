class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(auto it:queries){
            int r1=it[0];
            int r2= it[2];
            int c1= it[1];
            int c2= it[3];
            // traverse in row.. means from r1 to r2

            for(int i=r1;i<=r2;i++){
                dp[i][c1]++;

                if(c2+1<n)
                dp[i][c2+1]--;
            }

        }

        for(int i=0;i<n;i++){
            int sm=0;
            for(int j=0;j<n;j++){
                sm+=dp[i][j];
                dp[i][j]=sm;
            }
        }
        return dp;
    }
};