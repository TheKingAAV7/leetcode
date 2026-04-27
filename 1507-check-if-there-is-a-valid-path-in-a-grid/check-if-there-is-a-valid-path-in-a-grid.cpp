class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        /*


        1-> R,L
        2-> U,D
        3-> R,U
        4-> U,L
        5-> R,D
        6-> D,L 

        */
        map<int,set<char>>allowed;
        allowed[1] = {'L','R'};
        allowed[2] = {'U','D'};
        allowed[3] = {'L','D'};
        allowed[4] = {'R','D'};
        allowed[5] = {'L','U'};
        allowed[6] = {'R','U'};
 
        map<int,vector<vector<int>>>mp;
        mp[1]={{0,1,'R'},{0,-1,'L'}};
        mp[2]={{1,0,'D'},{-1,0,'U'}};
        mp[3]={{0,-1,'L'},{1,0,'D'}};
        mp[4]={{0,1,'R'},{1,0,'D'}};
        mp[5]={{0,-1,'L'},{-1,0,'U'}};
        mp[6]={{0,1,'R'},{-1,0,'U'}};

        int n= grid.size();
        int m= grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        // vector<int>dx={-1,1,0,0};
        // vector<int>dy={0,0,1,-1};
        // string dir="UDRL";
        queue<array<int,2>>q;
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty()){
            auto cur= q.front();
            q.pop();
            int x= cur[0];
            int y= cur[1];
            int val= grid[x][y];

            // cout<<x<<" "<<y<<endl;
            
            if(x==n-1 and y==m-1) return true;
            // cout<<x<<" "<<y<<endl;
            for(auto it:mp[val]){
                int nx= x+ it[0];
                int ny= y+it[1];
                char direction= char(it[2]);
                if(direction=='L') direction='R';
                else if(direction=='R') direction = 'L';
                else if(direction == 'U') direction = 'D';
                else direction = 'U';
                // cout<<nx<<" "<<ny<<" "<<direction<<endl;
                
                if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0 and  allowed[grid[nx][ny]].count(direction)>=1){
                    vis[nx][ny]=1;
                    // cout<<"PUSHED"<<endl;
                    q.push({nx,ny});
                }
            }
            // cout<<endl;
        }
        return 0;
    }
       
};