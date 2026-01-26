class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int best_difference=INT_MAX;
        for(int i=0;i<n-1;i++){
            int current_difference= arr[i+1]-arr[i];
            if(current_difference<best_difference){
                // ans.push_back({arr[i],arr[i+1]})
                ans={{arr[i],arr[i+1]}};  // initialize the answer vector
                best_difference= current_difference;
            }
            else if(current_difference==best_difference){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};