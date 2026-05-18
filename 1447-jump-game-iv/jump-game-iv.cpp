class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n= arr.size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        vector<int>vis(n,INT_MAX);
        set<int>done;
        q.push(0);
        vis[0]=0;
        while(!q.empty()){
            auto cur= q.front();q.pop();
            // cout<<cur<<" "<<arr[cur]<<endl;
            if(cur==n-1) return vis[cur];
            int lef= cur-1;
            int rig=cur+1;
            if(lef>=0 and vis[lef]==INT_MAX){
                vis[lef]=1+vis[cur];
                q.push(lef);
            }
            if(rig<n and vis[rig]==INT_MAX){
                vis[rig]=1+vis[cur];
                q.push(rig);
            }
            int x= arr[cur];
            if(done.find(x)==done.end()){
                for(int i:mp[x]){
                    if(vis[i]==INT_MAX){
                    vis[i]=1+vis[cur];
                    q.push(i);
                    }
                }
                done.insert(x);
            }
        }
        return -1;
    }
};