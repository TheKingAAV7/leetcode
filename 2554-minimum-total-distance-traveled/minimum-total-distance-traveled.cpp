#define ll long long
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        /*

        we have to choose the optimal factory for each robo

        Each factory may serve a range..
        dp[i][prev]
        
        */

        int m=robot.size();
        int n=factory.size();
        ll dp[101][101];
        memset(dp,-1,sizeof(dp));

        function<ll(int,int)>f=[&](int i, int p)->ll{
            if(p>=m) return 0ll;
            if(i>=n) return 1e12;
            if(dp[i][p]!=-1) return dp[i][p];

            ll ans=LLONG_MAX;
            //skip
            ll a1=f(i+1,p);
            ll cost=0;
            for(int idx=p;idx<m;idx++){
                int cnt= idx-p+1;
                int limit= factory[i][1];
                int pos= factory[i][0];
                cost+= abs(pos-robot[idx]);
                if(cnt<=limit){
                  ans=min(ans,cost+f(i+1,idx+1));
                }
                else break;
            }
            
            return dp[i][p]=min(a1,ans);
        };

        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        // for(int i:robot) cout<<i<<" ";
        // cout<<endl;
        // for(auto it:factory){
        //     cout<<"( "<<it[0]<<" "<<it[1]<<" ) ";
        // }

        return f(0,0);
        
    }
};