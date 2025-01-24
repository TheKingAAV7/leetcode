class Solution {
private:
vector<int>dp;
bool f(int node, vector<vector<int>>&graph){
    if(dp[node]!=-1) return dp[node];
    // assume node as unsafe;
    dp[node]=0;
    for(auto it:graph[node]){
        if(!f(it,graph)){
            return false;
        }
    }
    dp[node]=1;
    return true;
}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        dp.resize(n,-1);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(f(i,graph)){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};