class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size(),m=grid[0].size();
        vector<int>v;
        for(auto it:grid){
            for(auto i:it) v.push_back(i);
        }
        int ans=0;
        sort(v.begin(),v.end());
        int tar=v[v.size()/2];
    
        for(auto it:grid){
            for(auto i:it){
                
                if((i-tar)%x!=0) {
                    cout<<i<<endl;
                return -1;
                }
              // cout<<abs((i-tar)/x)<<endl;
                ans+=(abs((i-tar)/x));
            }
        }
        

        return ans;
    }
};