class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n= grid.size();
        int m= grid[0].size();
        int prev=-1;
        vector<int>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cur= grid[i][j]%x;
                v.push_back(grid[i][j]);
                if(prev==-1){
                    prev= cur;
                }
                else if(prev!=cur) return -1;
            }
        }
        sort(v.begin(),v.end());
        n= v.size();
        int mid= v[n/2];
        // cout<<mid<<endl;
        int ans=0;
        for(int i:v){
         int diff= abs(i-mid);
         ans+= diff/x;
        }
        return ans;
    }
};