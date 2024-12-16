class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& hts) { 
        int n=hts.size();
        int m=hts[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        priority_queue<tuple<int, int, int>,vector<tuple<int, int,int>>,greater<>>pq;
        pq.push(make_tuple(0,0,0));
        while(!pq.empty()){
            auto [x,y,z]=pq.top();
            pq.pop();
            //up
            if(y-1>=0){
                int maxi=max(x,abs(hts[y][z]-hts[y-1][z]));
                if(maxi<dist[y-1][z]){
                    dist[y-1][z]=maxi;
                pq.push(make_tuple(maxi,y-1,z));
                }
            }
            //down
            if(y+1<n){
                int maxi=max(x,abs(hts[y][z]-hts[y+1][z]));
                if(maxi<dist[y+1][z]){
                     dist[y+1][z]=maxi;
                pq.push(make_tuple(maxi,y+1,z));
                }
            }
            //right
            if(z+1<m){
                int maxi=max(x,abs(hts[y][z]-hts[y][z+1]));
                if(maxi<dist[y][z+1]){
                     dist[y][z+1]=maxi;
                pq.push(make_tuple(maxi,y,z+1));
                }
            }
            //left
            if(z-1>=0){
                int maxi=max(x,abs(hts[y][z]-hts[y][z-1]));
                if(maxi<dist[y][z-1]){
                     dist[y][z-1]=maxi;
                pq.push(make_tuple(maxi,y,z-1));
                }
            }
            
        }
        
        return dist[n-1][m-1];
        
         }
};