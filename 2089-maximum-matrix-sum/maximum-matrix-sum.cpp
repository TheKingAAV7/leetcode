#define ll long long
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll sm=0;
        int n=matrix.size();
        int m= matrix[0].size();
        int neg=0;
        ll mini=INT_MAX;
        int zer=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) zer=1;
                if(matrix[i][j]<0) {
                    
                    neg++;
                }
                mini= min(mini,(ll)abs(matrix[i][j]));
                sm+= abs(matrix[i][j]);
            }
        }
        cout<<neg<<" "<<sm<<endl;
        if(neg%2==0){
            return sm;
        }
        if(zer) return sm;
        return sm-2ll*mini;
    }
};