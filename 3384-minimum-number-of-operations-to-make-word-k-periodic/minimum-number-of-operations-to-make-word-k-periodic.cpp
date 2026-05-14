class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n= word.size();
        unordered_map<string,int>mp;
        int ans=0;
        for(int i=0;i<n;i+=k){
            string s=word.substr(i,k);
            
            mp[s]++;
            ans=max(ans,mp[s]);
        }
        return n/k - ans;
    }
};