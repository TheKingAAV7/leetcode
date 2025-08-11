class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        vector<int>v;
        int mod=1e9+7;
        for(int i=0;i<31;i++){
            if((n>>i)&1){
                v.push_back(1<<i);
            }
        }
        vector<int>ans;
        for(auto it:q){
            long long prod=1;
            for(int i=it[0];i<=it[1];i++){
                prod=(prod*v[i])%mod;
            }
            ans.push_back(prod);
        }
        return ans;
    }
};