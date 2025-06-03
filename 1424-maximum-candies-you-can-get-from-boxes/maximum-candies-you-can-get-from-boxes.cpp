class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& contained, vector<int>& initials) {
        int n=status.size();
        vector<int>found(n,0);
        
        vector<int>vis(n,0);
       
        int ans=0;
         queue<int>q;
        for(int i:initials){

           
            found[i]=1;
            if(vis[i]==0 and status[i]){
                q.push(i);
                
                while(!q.empty()){
                    int node=q.front();q.pop();
                    if (vis[node]) continue;
                    vis[node]=1;
                    ans+=candies[node];
                    for(auto key:keys[node]){
                        status[key]=1;
                        if(found[key] and vis[key]==0) q.push(key);
                        
                    }
                    for(auto adj_node : contained[node]){
                        found[adj_node] = 1;
                        if(vis[adj_node] == 0 and status[adj_node]){
                            q.push(adj_node);
                        }
                    }
                    
                }
            }
            
        }

        return ans;
    }
};