class Solution {
public:
    vector<vector<int>>dp;
    int f(int lef, int rig, vector<int>&val){
        if(lef+1==rig) return 0;
        if(dp[lef][rig]!=-1) return dp[lef][rig];
        int ans=INT_MAX;
        for(int k=lef+1;k<rig;k++){
            ans=min(ans,(val[lef]*val[k]*val[rig])+f(lef,k,val)+f(k,rig,val));
        }
        return dp[lef][rig]=ans;
    }
    int minScoreTriangulation(vector<int>& val) {
        int n=val.size();
        dp.resize(n,vector<int>(n,-1));
        return f(0,n-1,val);
        
    }
};