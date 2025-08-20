class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        // 9 + 4 + 1  ceil(n/i);
        /*
        1 1 1 1 
        1 1 1 1
        1 1 0 1 
        1 1 1 1 
        */

        int ans=0;
        int n=mat.size(),m=mat[0].size();

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++) cout<<mat[i][j]<<" ";
        //     cout<<endl;
        // }
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]==1){
                    dp[i][j]=1+min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
                }
            }
        }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                ans+=dp[i][j];
            }
            
        }
        return ans;

        
    }
};