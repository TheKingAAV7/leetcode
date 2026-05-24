class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n= arr.size();
        int fans=0;

        auto f=[&](auto &&self,int i, vector<int>&dp)->int{
            if(dp[i]!=-1) return dp[i];
            int mx=-1;
            int ans=0;
            for(int idx=i+1;idx<=min(i+d,n-1);idx++){
                if(arr[i]>mx and arr[i]>arr[idx]){
                    ans=max(ans,self(self,idx,dp));
                }
                else break;
                mx=max(mx,arr[idx]);
            }
            mx=-1;
            for(int idx=i-1;idx>=max(0,i-d);idx--){
                if(arr[i]>mx and arr[i]>arr[idx]){
                    ans=max(ans,self(self,idx,dp));
                }
                else break;
                mx=max(mx,arr[idx]);
            }
            return dp[i]= 1+ans;
        };
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
            int cur= f(f,i,dp);
            // if(cur==5) cout<<i<<endl;
            fans=max(fans,cur);
        }
        return fans;
    }
};