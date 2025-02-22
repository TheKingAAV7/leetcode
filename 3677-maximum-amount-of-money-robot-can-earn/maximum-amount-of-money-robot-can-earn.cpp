class Solution {
private:
long long dp[501][501][3];
long long f(int i, int j, int cnt,vector<vector<int>>&coins,int n, int m){
    if(i>n-1 || j>m-1) return INT_MIN;
    if(i==n-1 and j==m-1){
        if(coins[i][j]>=0) return coins[i][j];
        if(cnt<2) return 0;
        return coins[i][j];
    }
    if(dp[i][j][cnt]!=INT_MIN) return dp[i][j][cnt];
    long long  dow=INT_MIN,rig=INT_MIN;
    if(coins[i][j]>0){
    dow=coins[i][j]+f(i+1,j,cnt,coins,n,m);
    rig=coins[i][j]+f(i,j+1,cnt,coins,n,m);
    return dp[i][j][cnt]=max(dow,rig);
    }
    //neutralize or don't

    
    dow = coins[i][j] + f(i+1, j, cnt, coins, n, m);

    rig = coins[i][j] + f(i, j+1, cnt, coins, n, m);
    
    long long nd=INT_MIN,nr=INT_MIN;
    if(cnt<2){
        nd=f(i+1,j,cnt+1,coins,n,m);
        nr=f(i,j+1,cnt+1,coins,n,m);
    }
    return dp[i][j][cnt]= max({rig,dow,nd,nr});
}
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        for(int i=0; i<=500; i++)
    for(int j=0; j<=500; j++)
        for(int k=0; k<3; k++)
            dp[i][j][k] = INT_MIN;
        return f(0,0,0,coins,n,m);
    }
};