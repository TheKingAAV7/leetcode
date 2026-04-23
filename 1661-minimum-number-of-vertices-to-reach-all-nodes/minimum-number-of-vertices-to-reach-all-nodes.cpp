class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>deg(n,0);
        for(auto &it:edges){
            deg[it[1]]=true;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(deg[i]==0) ans.push_back(i);
        }
        return ans;
    }
};