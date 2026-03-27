class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k%=m;
        vector<vector<int>>prev=mat;
        for(int i=0;i<n;i++){
            bool ev= (i%2==0);
            vector<int>tmp;
            for(int j=0;j<m;j++){
                int idx=0;
                if(ev)
                 idx=(j+k)%m; 
                 else idx= (j - k + m) % m;
                 
                tmp.push_back(mat[i][idx]);
            }
            mat[i]=tmp;
        }
        return mat==prev;
        

    }
};