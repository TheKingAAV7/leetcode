class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& arr, int k) {
        int n=arr.size();
        int m=arr.size();
        sort(arr.begin(),arr.end(),[&](vector<int>&a,vector<int>&b)->bool{
            return a[k]>b[k];
        });
        return arr;
    }
};