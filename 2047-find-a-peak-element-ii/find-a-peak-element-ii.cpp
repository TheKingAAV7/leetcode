class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int mid=j;
            int lef= (mid-1>=0)?(mat[i][mid-1]<mat[i][mid]):1;
            int rig=(mid+1<m)?(mat[i][mid+1]<mat[i][mid]):1;
            int up= (i+1<n)?(mat[i+1][mid]<mat[i][mid]):1;
            int down=(i-1>=0)?(mat[i-1][mid]<mat[i][mid]):1;
            if(lef and rig and up and down ) return {i,mid};
        }
       } 
      return {-1,-1};
    }
};