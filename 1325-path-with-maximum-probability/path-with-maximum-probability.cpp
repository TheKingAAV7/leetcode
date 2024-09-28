class Solution {
private: 
void f(int n, unordered_map<int,vector<pair<int,double>>>&mp,int start, int end, vector<double>&ans){
    priority_queue<pair<double,int>>pq;

    pq.push({1,start});
    while(!pq.empty()){
        int u= pq.top().second;
        double dis=pq.top().first;
        pq.pop();
        for(auto it: mp[u]){
            int v=it.first;
            double w=it.second;
            if(dis*w > ans[v]){
                ans[v]=dis*w;
                pq.push({dis*w,v});
            }

        }

    }
}
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double>ans(n,0);
        ans[start]=1;
        unordered_map<int,vector<pair<int,double>>>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back({edges[i][1],succProb[i]});
            mp[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        f(n,mp,start, end,ans);
        return ans[end];


    }
};