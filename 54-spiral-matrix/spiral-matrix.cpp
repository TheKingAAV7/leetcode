class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>ans;
        //rdlu
        vector<int>dx={0,1,0,-1};
        vector<int>dy={1,0,-1,0};
        int cnt=0;
        int MAX= n*m;

        int i=0,j=0;
        int dir=0;

        while(true){
            if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1) break;
            if(dir==0){//r
                while(j<m and vis[i][j]==0){
                    vis[i][j]=1;
                    ans.push_back(mat[i][j]);
                    j++;
                }
                j--;
                i++;
                dir=1;
            }
            else if(dir==1){//d
                while(i<n and vis[i][j]==0){
                    vis[i][j]=1;
                    ans.push_back(mat[i][j]);
                    i++;
                }
                i--;
                j--;
                dir=2;
            }
            else if(dir==2){
                while(j>=0 and vis[i][j]==0){
                    vis[i][j]=1;
                    ans.push_back(mat[i][j]);
                    j--;
                }
                j++;
                i--;
                dir=3;
            }
            else{
                while(i>=0 and vis[i][j]==0){
                    vis[i][j]=1;
                    ans.push_back(mat[i][j]);
                    i--;
                }
                i++;
                j++;
                dir=0;
            }
        }
        return ans;
    }
};