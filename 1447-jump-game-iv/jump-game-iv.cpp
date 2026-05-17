class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n= arr.size();
        vector<int>vis(n,INT_MAX);
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        /*

        th1= > bring done section to up
        


        */
        set<int>done;
        queue<int>q;
        q.push(0);
        vis[0]=0;
        while(!q.empty()){
            auto cur= q.front(); q.pop();
            if(cur==n-1) return vis[cur];
            int lef= cur-1;
            int rig= cur+1;
            if(lef>=0 and vis[lef]==INT_MAX){
                vis[lef]= vis[cur]+1;
                q.push(lef);
            }
            if(rig<n and vis[rig]==INT_MAX){
                vis[rig]=vis[cur]+1;
                q.push(rig);
            }
            if(done.count(arr[cur])) continue;
            for(int idx:mp[arr[cur]]){
                if(idx!=cur){
                    if(vis[idx]>1+vis[cur]){
                    vis[idx]= 1+vis[cur];
                    q.push(idx);
                    }
                }
            }
            done.insert(arr[cur]);
        }
        return -1;

        
    }
};