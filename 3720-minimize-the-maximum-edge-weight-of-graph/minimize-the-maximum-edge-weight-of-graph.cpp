class Solution {
private:
int f(int i, int mid,vector<vector<pair<int,int>>>&adj,vector<int>&vis){
    int res=vis[i]=1;
    for(auto [j,w]:adj[i]){
        if(w<=mid and !vis[j]){
            res+=f(j,mid,adj,vis);
        }
    }
    return res;
}
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
     vector<vector<pair<int,int>>>adj(n);
     for(auto it:edges) adj[it[1]].push_back({it[0],it[2]});
     int lo=0,hi=1e6+1;
     int ans=-1;
     while(lo<=hi){
        int mid=(lo+hi)>>1;
        vector<int>vis(n,0);
        if(f(0,mid,adj,vis)==n){
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
     }   
     return ans;
    }
};