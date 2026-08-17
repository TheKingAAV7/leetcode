class Solution {
public:
    int stoneGameV(vector<int>& arr) {
        int n= arr.size();
        vector<int>pref(n+1,0);
        pref[0]=0;
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+arr[i];
        }

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        auto f=[&](auto &&self, int lef, int rig)->int{
            if(lef>=rig) return 0;
            if(dp[lef][rig]!=-1) return dp[lef][rig];
            int score=0;
            int total= pref[rig+1]-pref[lef];
            for(int j=lef;j<rig;j++){
                int lefsm= pref[j+1]-pref[lef];
                int rigsm= total-lefsm;
                int cur,cur1;
                cur=cur1=0;
                if(lefsm>rigsm) cur= rigsm+self(self,j+1,rig);
                else if(rigsm>lefsm) cur1=lefsm+self(self,lef,j);
                else{
                    cur= rigsm+self(self,j+1,rig);
                    cur1=lefsm+self(self,lef,j);
                } 
                score=max({score,cur,cur1});
            }
            return dp[lef][rig]=score;
        };

        return f(f,0,n-1);
        
    }
};