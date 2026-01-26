class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int sm=0;
        vector<vector<int>>ans;
        int mn=INT_MAX;
        for(int i=1;i<arr.size();i++){
            sm= arr[i]-arr[i-1];
            if(sm<mn){
                mn=sm;
                ans= {{arr[i-1],arr[i]}};
            }
            else if(sm==mn) ans.push_back({arr[i-1],arr[i]});
        }
        return ans;
    }
};