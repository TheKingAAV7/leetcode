class Solution {
public:
    vector<int> sumZero(int n) {
       
        int sum=0;
        vector<int>ans;
        
        for(int i=1;i<=n-1;i++){
            ans.push_back(i);
            sum+=i;
        }
        ans.push_back(-1*sum);
        return ans;
        
    }
};