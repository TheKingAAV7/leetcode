#define ll long long
class Solution {
public:
    long long countStableSubarrays(vector<int>& arr) {
        int n=arr.size();
        map<pair<int,ll>,int>mp;
        
        ll sm=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            sm+=arr[i];
            ll reqd=(sm-2*arr[i]);
            pair<int,ll>x={arr[i],reqd};
            if(mp.find(x)!=mp.end()) ans+= mp[x];
            mp[{arr[i],sm}]++;
        }
        int ext=0;
        for(int i=1;i<n;i++){
            if(arr[i]==0 and arr[i-1]==0) ext++;
        }

        return ans-ext;
        
    }
};