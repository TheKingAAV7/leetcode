typedef long long ll;
// T.C and S.C are O(N∗K)
class Solution {
public:
ll mini = -1e14;
ll calcul( vector<int>& prices, vector<vector<vector<ll>>>&dp, int i, int k, int type ){
if( i == prices.size() ){
if( type == 0 ) return 0;
else return mini;
}

    if( dp[i][k][type] != mini ) return dp[i][k][type];
    if( k == 0 && type == 0 ) return 0;

    ll profit = mini;
    // do nothing
    profit = max( profit , calcul(prices,dp,i+1,k,type) );
    // operation_type - 1 
    if( type == 0 ){
        // buy stock here
        profit = max( profit , calcul(prices,dp,i+1,k,1) - 1LL*prices[i] );
        // sell stock first ( transaction-2 )
        profit = max( profit , calcul(prices,dp,i+1,k,2) + 1LL*prices[i] );
    }else if( type == 1 && k > 0 ){
        // sell it
        profit = max( profit , calcul(prices,dp,i+1,k-1,0) + 1LL*prices[i]);
    }else if( type == 2 && k > 0 ){
        // buy it
        profit = max( profit , calcul(prices,dp,i+1,k-1,0) - 1LL*prices[i]);
    }

    return dp[i][k][type] = profit;


}

long long maximumProfit(vector<int>& prices, int k) {
    int n = prices.size();
    vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(k+1,vector<ll>(3,mini)));
    // 0 -> free, 1 -> holding ( transaction-1 ), 2-> sold( transaction-2 )

    ll ans = calcul(prices,dp,0,k,0);
    return ans;
}
};