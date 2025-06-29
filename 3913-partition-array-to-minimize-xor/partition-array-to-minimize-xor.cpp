class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,INT_MAX));
        int xoro=0;
        for(int i=0;i<n;i++){
            xoro^=nums[i];
            dp[i][1]=xoro;
        }
        for(int i=0;i<n;i++){
            for(int x=2;x<=k;x++){
                int xoro=0;
                int mini=INT_MAX;
                for(int j=i;j>=1;j--){
                   
                    xoro^=nums[j];
                    // if(i==1) cout<<x<<" "<<xoro<<endl;
                    mini=min(mini,max(xoro,dp[j-1][x-1]));
                }
                dp[i][x]=mini;
            }
        }
      
        return dp[n-1][k];
        
    }
};