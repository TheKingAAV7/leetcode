#define ll long long
class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        /*
        claim:
        1) if in set there are >=2 values of limit sum is the answer
        2) otherwise take top limit[0] ele sm;
        */
        int n=value.size();
        map<ll,vector<ll>>mp;
        for(int i=0;i<n;i++){
            mp[limit[i]].push_back(value[i]);
        }
        for(auto it:mp){
            sort(mp[it.first].begin(),mp[it.first].end());
        }
        ll ans=0;
        for(auto it:mp){
            int cnt=it.first;
            int i=it.second.size()-1;
            while(i>=0 and cnt--){
                ans+=it.second[i];
                i--;
            }
        }
        return ans;
    }
};