
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0)) ;
        queue<array<int,2>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1 ){ 
            if(board[i][j]=='O'){
            q.push({i,j});
            vis[i][j]=1;
            }
            }
            }
        }
       
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        while(!q.empty()){
            auto cur= q.front();
            q.pop();
            int x=cur[0];
            int y= cur[1];
            for(int k=0;k<4;k++){
                int nx= x+dx[k];
                int ny= y+dy[k];
                if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0 and board[nx][ny]=='O'){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0) board[i][j]='X';
                else board[i][j]='O';
            }
        }
        return;
    }
};