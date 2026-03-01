
/*
Think reverse

*/
class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>skipped(n,vector<int>(m,0));
        for(int b=18;b>=0;b--){
            bool canbe= true;
            vector<vector<int>>nksp= skipped;
            for(int i=0;i<n;i++){
                int cnt=0;
                for(int j=0;j<m;j++){
                    if(nksp[i][j]==0){

                        if((grid[i][j]>>b)&1==1){
                            nksp[i][j]=1;
                            cnt++;
                        }
                    }
                    else cnt++;
                }
                if(cnt==m){
                    canbe=false;
                    break;
                }
            }
            if(canbe)
            skipped= nksp;
            else ans|=(1<<b);
        }
        return ans;
    }
};