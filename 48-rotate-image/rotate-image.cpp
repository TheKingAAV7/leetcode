class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
      
        for(int i=0;i<n;i++){
            reverse(arr[i].begin(),arr[i].end());
        }
        
        
    }
};