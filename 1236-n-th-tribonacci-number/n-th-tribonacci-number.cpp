class Solution {
public:


    vector<vector<int>>multiply(vector<vector<int>>&a,vector<vector<int>>&b){
        int n1=a.size();
        int m1=a[0].size();
        int n2=b.size();
        int m2=b[0].size();
        assert(m1==n2);
        vector<vector<int>>ans(n1,vector<int>(m2,0));
        for(int i=0;i<n1;i++){
            for(int j=0;j<m2;j++){
                for(int k=0;k<m1;k++){
                ans[i][j]+=(a[i][k]*b[k][j]);
                }
            }
        }
        return ans;
    }
    vector<vector<int>>f(vector<vector<int>>&a,int b){
        if(b==0){
            return {{1,0,0},{0,1,0},{0,0,1}};
        }
        vector<vector<int>>half=f(a,b/2);
        vector<vector<int>>ans=multiply(half,half);
        if(b%2) ans=multiply(ans,a);
        return ans;
    }
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<=2) {
            return 1;
        }
        vector<vector<int>>magic={
        {1,1,0},
        {1,0,1},
        {1,0,0}
        };

        vector<vector<int>>base={
        {1,1,0}
        };
        int po= n-2;
        vector<vector<int>>pmag=f(magic,po);
        vector<vector<int>>ans= multiply(base,pmag);
        return ans[0][0];

    }
};