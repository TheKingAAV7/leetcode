class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& arr, int n) {
        vector<int>ans(n+2,0);
        for(auto it:arr){
            ans[it[0]]+=it[2];
            ans[it[1]+1]-=it[2];
        }
        int pref=0;
        for(int i=1;i<=n;i++){
           ans[i]+=ans[i-1];
        }
        ans.erase(ans.begin());
        ans.pop_back();
        
        return ans;
    }
};