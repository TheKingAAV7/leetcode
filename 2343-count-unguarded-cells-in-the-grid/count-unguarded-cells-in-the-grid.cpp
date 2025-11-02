class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(auto it:guards) vis[it[0]][it[1]]=1;
        for(auto it:walls) vis[it[0]][it[1]]=2;

        for(int i=0;i<n;i++){
            bool g=false;
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                    g=true;
                    continue;
                }
                if(vis[i][j]==2){
                    g=false;
                    continue;
                }
                if(g) vis[i][j]=3;
            }
        }
        for(int i=0;i<n;i++){
            bool g=false;
            for(int j=m-1;j>=0;j--){
                if(vis[i][j]==1){
                    g=true;
                    continue;
                }
                if(vis[i][j]==2){
                    g=false;
                    continue;
                }
                if(g) vis[i][j]=3;
            }
        }

        for(int j=0;j<m;j++){
            bool g=false;
            for(int i=0;i<n;i++){
                if(vis[i][j]==1){
                    g=true;
                    continue;
                }
                if(vis[i][j]==2){
                    g=false;
                    continue;
                }
                if(g) vis[i][j]=3;
            }
        }

        for(int j=0;j<m;j++){
            bool g=false;
            for(int i=n-1;i>=0;i--){
                if(vis[i][j]==1){
                    g=true;
                    continue;
                }
                if(vis[i][j]==2){
                    g=false;
                    continue;
                }
                if(g) vis[i][j]=3;
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0) ans++;
            }
        }
        return ans;


    }
};