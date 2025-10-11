class Solution {
public:
    vector<long long>dp;
    long long f(int i ,vector<int>&v,int &n, map<int,int>&mp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        //ntake
        long long ans1=f(i+1,v,n,mp);
        long long ans2=0;
        
        auto it=lower_bound(v.begin(),v.end(),v[i]+3);
        int idx=it-v.begin();
        ans2=1ll*mp[v[i]]*v[i] + f(idx,v,n,mp);
        return dp[i]=max(ans1,ans2);
        

    }
    long long maximumTotalDamage(vector<int>& arr) {
        map<int,int>mp;
        for(int i:arr) mp[i]++;
        set<int>st(arr.begin(),arr.end());
        vector<int>v(st.begin(),st.end());
        
        int n=v.size();
        dp.resize(n,-1);
        return f(0,v,n,mp);

    }
};