class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n= arr.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            int lef= i-arr[i];
            int rig= i+arr[i];
            if(lef>=0) adj[i].push_back(lef);
            if(rig<n) adj[i].push_back(rig);
        }
        queue<int>q;
        vector<int>vis(n,0);
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            auto cur= q.front();q.pop();
            if(arr[cur]==0) return true;
            for(auto it:adj[cur]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return false;
    }
};