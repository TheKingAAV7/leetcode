class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n=days.size();
        int maxi=days.back();
        vector<int>dp(maxi+1,INT_MAX);
        dp[maxi]=min({cost[0],cost[1],cost[2]});
        for(int i=n-2;i>=0;i--){
            //1-day pass
            dp[days[i]]=min(dp[days[i]],cost[0]+dp[days[i+1]]);
            //7-day pass
            auto it1=upper_bound(days.begin(),days.end(),days[i]+6);
            if(it1==days.end()){
                dp[days[i]]=min(cost[1],dp[days[i]]);
            } 
            else{
                dp[days[i]]=min(dp[days[i]],cost[1]+dp[*it1]);
            }
            //30-day pass
             auto it2=upper_bound(days.begin(),days.end(),days[i]+29);
             if(it2==days.end()){
                dp[days[i]]=min(cost[2],dp[days[i]]);
            } 
            else{
                dp[days[i]]=min(dp[days[i]],cost[2]+dp[*it2]);
            }
        }
        return dp[days[0]];
    }
};