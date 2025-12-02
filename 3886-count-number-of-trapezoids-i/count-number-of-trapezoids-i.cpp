class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,int>mp;
        int mod=1e9+7;
        for(auto it:points){
            mp[it[1]]++;
        }
        vector<long long>v;
        for(auto it:mp){
            v.push_back(it.second);
        }
        long long ans=0;
        long long sm=0;
        for(int i=v.size()-1;i>=0;i--){
            long long cnt=v[i];
            
            long long tmp= (cnt *(cnt-1))%mod;
            tmp= tmp/2;

            ans = ((ans)%mod + (tmp*sm)%mod)%mod;

            sm= (sm + tmp)%mod;

        }
        return ans;
    }
};