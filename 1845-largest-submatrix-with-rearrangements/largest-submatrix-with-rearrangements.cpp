class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
       
        int n=matrix.size();
        int m=matrix[0].size();
        // 1  2 2 3 4 5   

        vector<int>ht(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]){
                    ht[j]++;
                }
                else ht[j]=0;
            }
            vector<int>tmp=ht;
            sort(tmp.begin(),tmp.end());
            
        for(int j=0;j<m;j++) ans=max(ans,(tmp[j]*(m-j)));
        }
        
   
        return ans;
    }
};