class Solution {
private:
int mod=1e9+7;
public:
    int numOfSubarrays(vector<int>& arr) {
       
        int n=arr.size();
         vector<int>pref(n,0);
        pref[0]=arr[0];
        for(int i=1;i<n;i++){
           pref[i]+=(pref[i-1]+arr[i]); 
        }
        vector<pair<int,int>>suff(n,{0,0});
     
        int odd=0,even=0;
        for(int i=n-1;i>=0;i--){
            suff[i]={odd,even};
            if(pref[i]%2){
                odd++;
            }
            else even++;
        }
        int sm=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            
            if((sm&1)^(arr[i]&1)==1){
                if(arr[i]%2) ans=(ans+suff[i].first+1)%mod;
                else ans=(ans+suff[i].second);
            }
            else{
                
                if(arr[i]%2){
                 
                 ans=(ans+suff[i].second+1)%mod;
                }
                else ans=(ans+suff[i].first);
            }
            sm+=arr[i];
     //   cout<<arr[i]<<" "<<ans<<endl;
        }
        // cout<<endl;
        // for(auto it:suff) cout<<it.first<<" "<<it.second<<endl;
        // for(auto it:pref) cout<<it<<" ";
        // cout<<endl;
        return ans;
    }
};