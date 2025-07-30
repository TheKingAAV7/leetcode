class Solution {
public:
    int maximizeWin(vector<int>& pp, int k) {
        int n=pp.size();
        vector<int>dp(n+1,0);
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int x=pp[i]+k;
            auto it=upper_bound(pp.begin(),pp.end(),x);
            it--;
            int idx=it-pp.begin();
            int sz=idx-i+1;
            dp[i]=max({dp[i],dp[i+1],sz});
            ans=max(ans,sz+dp[idx+1]);
        }
        
        return ans;
        
    }
};