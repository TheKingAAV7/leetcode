class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& arr, int k) {
        int n=arr.size();
        int m=arr.size();
        vector<int>pos(n,0);
        iota(pos.begin(),pos.end(),0);
        sort(pos.begin(),pos.end(),[&](int a, int b)->bool{
            return arr[a][k]>arr[b][k];
        });
        vector<vector<int>>ans;
        for(auto i:pos){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};