class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        /*

        We can either choose current element which will give us {x,y} 
        or don't choose it

        so, the state will be

        dp[i][j][k] => largest subset of strs will ith postion, suchat that there are atmost
        m 0's and n 1's

        Transition:
        dp[i][j][k] = max(dp[i+1][j][k], dp[i+1][j-x][k-y]+1)

        */
        int N=strs.size();
        vector<array<int,2>>v(N);
        
        for(int i=0;i<N;i++){
            int cnt0=0,cnt1=0;
            for(char &c : strs[i]){
                if(c=='0') cnt0++;
                else cnt1++;
            }
            v[i]={cnt0,cnt1};
        }

        // for(auto [x,y]: v) cout<<x<<" "<<y<<" ";
        // cout<<endl;


        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(m+2,vector<int>(n+2,0)));

        for(int i=N-1;i>=0;i--){
            for(int j = 0; j<=m; j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k]= max(dp[i][j][k],dp[i+1][j][k]);
                    int zero=v[i][0];
                    int one= v[i][1];
                    if(k-one>=0 and j-zero>=0) dp[i][j][k]= max(dp[i][j][k],1+dp[i+1][j-zero][k-one]);
                }
            }
        }




        return dp[0][m][n];
    }
};