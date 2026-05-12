class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>>ans;
        int n= graph.size();

        auto f=[&](auto &&self, int node, vector<int>&path)->void{
            if(node==n-1){
                path.push_back(node);
                ans.push_back(path);
                path.pop_back();
                return;
            }
            for(auto it:graph[node]){
                path.push_back(node);
                self(self,it,path);
                path.pop_back();
            }
        };
        vector<int>tmp;
        f(f,0,tmp);
        return ans;
    }
};