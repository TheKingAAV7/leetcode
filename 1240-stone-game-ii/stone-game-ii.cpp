class Solution {
public:
    int stoneGameII(vector<int>& arr) {

        int n= arr.size();

        vector<int>pref(n+1,0);
        
        for(int i=0;i<n;i+=1){
            pref[i+1]= arr[i]+pref[i];
        }

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(2,-1)));

        auto f=[&](auto &&self, int i, int M, int turn )->int{
            if(i>=n) return 0;

            if(dp[i][M][turn]!= -1) return dp[i][M][turn];

            int ans;

            if(!turn){
                ans=0;

                for(int x=1;x<=2*M;x++){
                    int lef=i;
                    int rig=i+x-1;

                    if(rig<n)
                        ans=max(ans,
                            2*(pref[rig+1]-pref[lef]) +
                            self(self,i+x,max(M,x),!turn)
                        );
                }
            }
            else{
                ans=1e9;

                for(int x=1;x<=2*M;x++){
                    int lef=i;
                    int rig=i+x-1;

                    if(rig<n)
                        ans=min(ans,
                            self(self,i+x,max(M,x),!turn)
                        );
                }   
            }

            return dp[i][M][turn]= ans;
        };

        int val=f(f,0,1,0);

        return val/2;
    }
};