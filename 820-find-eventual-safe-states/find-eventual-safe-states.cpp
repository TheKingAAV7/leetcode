class Solution {
private:
bool f(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&rec){
    vis[node]=1;
    rec[node]=1;
    for(auto it:graph[node]){
        if(vis[it]==0){
           if( f(it,graph,vis,rec)) return true;
        }
        else if(rec[it]==1){
            return true;
        }
    }
    rec[node]=0;
    return false;
}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0),rec(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                f(i,graph,vis,rec);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(rec[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};