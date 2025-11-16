class Solution {
public:
    int numSub(string s) {
        int n=s.length();
        int mod=1e9+7;
        int cnt=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') cnt++;
            else{
                long long cur=(1ll*cnt*(cnt+1))/2;
                ans= (ans+cur)%mod;
                cnt=0;
            }
        }
        long long cur=(1ll*cnt*(cnt+1))/2;
        ans= (ans+cur)%mod;
        return (int)ans;
    }
};