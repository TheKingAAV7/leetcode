class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>rmax(n,0),cmax(m,0);
        for(int i=0;i<n;i++){
            int maxi=0;
            for(int j=0;j<m;j++) maxi=max(maxi,grid[i][j]);
            rmax[i]=maxi;
        }
        for(int j=0;j<m;j++){
            int maxi=0;
            for(int i=0;i<n;i++) maxi=max(maxi,grid[i][j]);
            cmax[j]=maxi;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               // cout<<min(rmax[i],cmax[j])<<" ";
             ans+=(min(rmax[i],cmax[j])-grid[i][j]);
            }
           // cout<<endl;
        }
        return ans;
    }
};