class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n= arr.size();
        // vector<vector<int>>adj(n);
       
        queue<int>q;
        vector<int>vis(n,0);
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            auto i= q.front();q.pop();
            if(arr[i]==0) return true;
            int lef= i-arr[i];
            int rig= i+arr[i];
            if(lef>=0 and !vis[lef]){
                q.push(lef);
                vis[lef]=1;
            } 
            if(rig<n){
             q.push(rig);
             vis[rig]=1;
            }
        }
        return false;
    }
};