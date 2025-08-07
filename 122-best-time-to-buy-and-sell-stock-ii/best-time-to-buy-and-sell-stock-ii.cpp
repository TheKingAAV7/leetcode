class Solution {
public:
    int maxProfit(vector<int>& pr) {
        int n=pr.size();
        vector<int>pos(n,-1);
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() and pr[i]>pr[st.top()]){
                pos[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            if(pos[i]!=-1){
                dp[i]=max(dp[i],(pr[pos[i]]-pr[i])+dp[pos[i]]);
            }
            dp[i]=max(dp[i+1],dp[i]);
            ans=max(ans,dp[i]);
        }
        //for(int i:dp) cout<<i<<" ";
        
        return ans;
    }
};