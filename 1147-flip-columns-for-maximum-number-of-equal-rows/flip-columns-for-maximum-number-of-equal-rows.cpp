class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
       int ans=1;
       int m=matrix[0].size(),n=matrix.size();
       // 0 0 1  1 1 0   0 0 1
       for(int i=0;i<n;i++){
        vector<int>tmp(matrix[i].begin(),matrix[i].end());
        int cnt=1;
        
        for(int j=0;j<n;j++){
            int odd=1,even=1;
                if(j!=i){
                    vector<int>tmp1(m),tmp2(m);
                  for(int k=0;k<m;k++){
                    tmp1[k]=matrix[j][k];
                    tmp2[k]=!matrix[j][k];
                  }
                  if(tmp==tmp1 || tmp== tmp2){
                    cnt++;
                  }
                }
        }
        ans=max(cnt,ans);
       }
       return ans;

    }
};