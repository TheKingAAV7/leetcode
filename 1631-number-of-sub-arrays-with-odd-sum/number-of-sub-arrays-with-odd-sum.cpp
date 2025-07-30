class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
        int od=0,ev=0;
        int sm=0;
        int mod=1e9+7;
        for(int i=n-1;i>=0;i--){
            sm+=arr[i];
            if(arr[i]&1){
                ans= (ans+(1+ev))%mod;
                int newev=od;
                int newod=(1+ev)%mod;
                ev=newev;
                od=newod;
                
            }
            else{
                ans=(ans+od)%mod;
               int newod=od;
                int newev=(1+ev)%mod;
                ev=newev;
                od=newod;
                
            }
            //cout<<od<<" "<<ev<<endl;
        }
        return (int)ans;
    }
};