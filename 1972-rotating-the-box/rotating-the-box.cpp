class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        for(int i=0;i<n;i++){
            int lastempty=-1;
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]=='*'){
                    lastempty= j-1;
                }
                else if(mat[i][j]=='#'){
                    if(lastempty!=-1){
                        swap(mat[i][j],mat[i][lastempty]);
                        lastempty--;
                    }
                    else{
                        lastempty= j-1;
                    }
                }
                else{
                    lastempty=max(lastempty,j);
                }
            }
        }
        vector<vector<char>>ans(m);
        for(int j=0;j<m;j++){
            for(int i=n-1;i>=0;i--){
                ans[j].push_back(mat[i][j]);
            }
        }
        
        return ans;
    }
};