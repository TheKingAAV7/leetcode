class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& arr) {
        int p=31;
        int mod=1e9+9;
        long long ans=0;
        int m=arr.size();
        vector<string>arr2;
        for(auto it:arr){
            arr2.push_back(it);
        }

        for(auto &it:arr2)  reverse(it.begin(),it.end());
        unordered_map<int,int>mp;
        
        for(int j=0;j<m;j++){
            int n=arr[j].size();
            long long hash_val=0,hash_val1=0;
            long long pow=1;
            for(int i=0;i<n;i++){
               hash_val=(hash_val + (arr[j][i]-'a'+1)*pow) % mod;
               hash_val1=((hash_val1%mod)*p%mod)%mod +(arr2[j][i]-'a'+1)%mod;

               if(hash_val==hash_val1 and mp.find(hash_val)!=mp.end()){
                ans+=mp[hash_val];
               }
               pow=(pow*p)%mod;
            }
            mp[hash_val]++;

        }
        return ans;
    }
};