class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int n=mat.size(),m=mat[0].size();
    vector<int>ans;
    bool up=true;
    int i=0,j=0;
    while(true){
        if(up){
            while(i>=0 and j<m){
                ans.push_back(mat[i][j]);
                i--;
                j++;
            }
            i++;
            j--;
            int ni,nj;
            if(j+1>=m and i+1>=n) break;
            if(j+1>=m){
                ni=i+1;
                nj=j;
            }
            else{
                nj=j+1;
                ni=i;
            }
            i=ni;
            j=nj;
        }
        else{
            while(i<n and j>=0){
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
            i--;
            j++;
            int ni,nj;
            if(i+1>=n and j+1>=m) break;
            if(i+1>=n){
                ni=i;
                nj=j+1;
            }
            else{
                ni=i+1;
                nj=j;
            }
            i=ni;
            j=nj;
        }
        
        up=!up;
        //cout<<i<<" "<<j<<" "<<up<<endl;
    }
    return ans;
    }
};