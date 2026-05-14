class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n= word.size();
        unordered_map<string_view,int>mp;
        int ans=0;
        for(int i=0;i<n;i+=k){
            string_view s(word.data()+i,k);
            
            mp[s]++;
            ans=max(ans,mp[s]);
        }
        return n/k - ans;
    }
};