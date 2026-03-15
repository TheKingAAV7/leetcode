class Solution {
public:

    vector<vector<int>>multiply(vector<vector<int>>&a,vector<vector<int>>&b){
        int n1=a.size();
        int m1=a[0].size();
        int n2=b.size();
        int m2=b[0].size();
        assert(n2==m1);
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

    vector<vector<int>>f(vector<vector<int>>&base,int power){
        if(power==0){
            
            vector<vector<int>>ans(2,vector<int>(2,0));
            ans[0][0]=1;
            ans[1][1]=1;
            return ans;
        }
        vector<vector<int>>half= f(base,power/2);
        vector<vector<int>>ans= multiply(half,half);
        if(power&1) ans=multiply(ans,base);
        return ans;
    }
    int fib(int n) {

        /*

        2->1
        3->2


        */
        vector<vector<int>>base=
        {{1,1},
         {1,0}};
        if(n<=1) return n;
        vector<vector<int>>tmp={{1,0}};


        vector<vector<int>>magic=f(base,n-1);
        vector<vector<int>>ans=multiply(tmp,magic);
        // for(auto it:magic){
        //     for(int i:it) cout<<i<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;

        // for(auto it:ans){
        //     for(int i:it) cout<<i<<" ";
        //     cout<<endl;
        // }
        return ans[0][0];

    }
};