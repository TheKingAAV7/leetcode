class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<int>v(n,-1);
       
       for(int i=0;i<n;i++){
        
        if(v[i]==-1){
            queue<pair<int,int>>q;
            v[i]=0;
         
            q.push({i,0});
            while(!q.empty()){
                int node=q.front().first;
                int c=q.front().second;
                 q.pop();
                for(auto j:graph[node]){
                    if( v[j]==c) return false;
                    else{
                        if(v[j]==-1){
                            v[j]=!c;
                            q.push({j,!c});

                        }
                    }
                }
               
            }

        }
       }

       return true;
    }
};