#define ll long long
class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
      
        map<ll,ll>mp;
        set<vector<ll>>st;
        
        int n=nums.size();
        vector<ll>pref(n,0);

        ll ss=0;
        for(int i=0;i<n;i++){
            ss+=nums[i];
            pref[i]=ss;
        }
        mp[0]=-1;
        // for(ll i:pref) cout<<i<<" ";
        // cout<<endl;
        ll sm=0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            ll curm=sm%k;
            ll reqm= curm;
            if(mp.find(reqm)!=mp.end()){
                st.insert({mp[reqm]+1,i});
            }
            mp[curm] = i;
        }
        
        vector<vector<ll>>v(st.begin(),st.end());
        vector<long long> starts;
    starts.reserve(v.size());
    for (auto &row : v) starts.push_back(row[0]);
        vector<int>mpp(n+1,0);
        // for(auto it:v) cout<<it[0]<<" "<<it[1]<<endl;
        int N=v.size();
        vector<ll>dp(N+1,0);
        for(int i=N-1;i>=0;i--){
            //ntake
            dp[i]=max(dp[i+1],dp[i]);
            //take
            auto it=upper_bound(starts.begin()+i,starts.end(),v[i][1]);


            int idx=it-starts.begin();
           // cout<<idx<<endl;
            ll ssm=pref[v[i][1]]-pref[v[i][0]]+nums[v[i][0]];
           
            dp[i]=max(dp[i],dp[idx]+ssm);
        }

        // for(ll i:dp) cout<<i<<" ";
        // cout<<endl;
        return sm-dp[0];
    
    }
};