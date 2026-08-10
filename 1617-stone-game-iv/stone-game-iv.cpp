class Solution {
public:
    bool winnerSquareGame(int n) {
        
        int lim= sqrt(n);

        /*


        f(x,!turn)
        */ 

        vector<vector<int>>dp(n+1,vector<int>(2,-1));

        auto f=[&](auto &&self, int cur, int turn)->bool{
            if(cur==0)
            return !turn;

            if(dp[cur][turn]!=-1) return dp[cur][turn];
            int ans=0;

            for(int i=1;i<=lim;i++){
                int sq= i*i;
                if(cur>=sq){
                    int winner= self(self,cur-sq,!turn);
                  
                    if(winner ==turn) return dp[cur][turn]= winner; 
                }
            }

            // cout<<cur<<" "<<turn <<" "<<(!turn)<<endl;

            
            return dp[cur][turn]= !turn;
        };
        int winner= f(f,n,0);
        return winner==0;
    }
};