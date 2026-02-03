class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=0;
        int n=nums.size();

        vector<int>pref(n,0);
        int sm=0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            pref[i]=sm;
        }
        int K=25;
        vector<vector<int>>dp(n,vector<int>(K,INT_MIN));

        for(int i=0;i<n;i++) dp[i][0]=pref[i];
        
        for(int k=1;k<K;k++){
            for(int i=0;i+(1<<(k-1))<n;i++){
                dp[i][k]= max(dp[i][k-1], dp[i+(1<<(k-1))][k-1]);
                //cout<<i<<" "<<k<<" "<<dp[i][k]<<endl;
                
            }
        }

        auto f=[&](int l, int r)->int{
            int tans=INT_MIN;
            int dist= r-l+1;
            int idx=l;
            int pos=0;
            while(dist>0){
                if(dist&1){
                    tans= max(tans,dp[idx][pos]);
                    idx+=(1<<pos);
                }
                dist>>=1;
                pos++;
            }
            return tans;
        };


        // for(int i:pref) cout<<i<<" ";
        // cout<<endl;

        for(int i=0;i<n;i++){
            int tmp= f(i,n-1);
            int lefsm= (i-1>=0)?pref[i-1]:0;
           // cout<<tmp<<endl;
            int cursm= tmp-lefsm;
            ans=max(ans,cursm);
        }
        if(ans==0) return *max_element(nums.begin(),nums.end());
        return ans;
    }
};