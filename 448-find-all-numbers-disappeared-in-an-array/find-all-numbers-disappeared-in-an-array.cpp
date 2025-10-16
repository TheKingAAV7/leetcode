class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
        int n=arr.size();
        vector<int>vis(n+1,0);
        vector<int>ans;
        for(int i:arr){
            vis[i]=1;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]) ans.push_back(i);
        }
        return ans;

        
    }
};