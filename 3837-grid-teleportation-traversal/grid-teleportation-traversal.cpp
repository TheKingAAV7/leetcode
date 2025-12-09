class Solution {
public:
    int minMoves(vector<string>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int ro[]={-1,1,0,0};
        int col[]={0,0,-1,1};

        // adj[i][j].push_back({char,n+1})

        vector<vector<vector<array<int,3>>>> adj(n, vector<vector<array<int,3>>>(m));

        vector<array<int,3>>tele[26];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!='.' and mat[i][j]!='#'){
                    tele[mat[i][j]-'A'].push_back({i,j});
                    adj[i][j].push_back({1,mat[i][j]-'A',m+1});
                }
            }
        }

        vector<vector<int>>d1(n,vector<int>(m,INT_MAX));
        vector<int>d2(26,INT_MAX);
        // cost, i, j,  
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
        d1[0][0]=0;
        pq.push({0,0,0});
        

        while(!pq.empty()){
            auto cur= pq.top();
            pq.pop();

            int cost= cur[0];
            int i= cur[1];
            int j= cur[2];
            if(i==n-1 and j==m-1) return cost;
            if(j==m+1){
                if(cost>d2[i]) continue;
                for(auto it:tele[i]){
                   
                    int i1 = it[0];
                    int j1= it[1];
                    int ndist= cost ;
                    if(ndist<d1[i1][j1]){
                        d1[i1][j1]=ndist;
                        pq.push({ndist,i1,j1});
                    } 
                }
            }
            else{
                // this node can have two types of paths, teleport path or normal path
                // normal
                for(int k=0;k<4;k++){
                    int i1= i+ro[k];
                    int j1= j+col[k];
                    int ndist= 1+cost;
                    if(i1>=0 and i1<n and j1>=0 and j1<m and mat[i1][j1]!='#' and ndist<d1[i1][j1]){
                        d1[i1][j1]= ndist;
                        pq.push({ndist,i1,j1});
                    }
                }

                // tele
                for(auto it:adj[i][j]){
                    int w= it[0];
                    int i1= it[1];
                    int j1= it[2];
                    int ndist= cost;
                    if(ndist<d2[i1]){
                        d2[i1]=ndist;
                        pq.push({ndist,i1,j1});
                    }
                    
                }


            }
        }




        
        return -1;

        

        
        
    }
};