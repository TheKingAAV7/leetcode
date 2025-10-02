#define ll long long
class Solution {
public:
    void f(int node,vector<int>&arr,vector<vector<int>>&adj,vector<int>&vis,vector<ll>&ev,vector<ll>&od,
    priority_queue<ll>&pq){
        if(vis[node]) return; 
        vis[node]=1;
        pq.push(arr[node]);
        if(node%2) od.push_back(node);
        else ev.push_back(node);
        for(auto it:adj[node]){
            if(vis[it]==0){
                f(it,arr,adj,vis,ev,od,pq);
            }
        }
        return;



    }
    long long maxAlternatingSum(vector<int>& arr, vector<vector<int>>& edges) {
        int n=arr.size();
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int>vis(n,0);
        ll extr=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vector<ll>ev,od;
                priority_queue<ll>pq;
                f(i,arr,adj,vis,ev,od,pq);
                int pos1=0,pos2=0;
                while(pos1<ev.size()){
                    arr[ev[pos1]]=pq.top();pq.pop();
                    pos1++;
                }
                while(pos2<od.size()){
                    arr[od[pos2]]=pq.top();pq.pop();
                    pos2++;
                }
                
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            if(i&1) ans-=arr[i];
            else ans+=arr[i];
        }
        return ans;
    }
};