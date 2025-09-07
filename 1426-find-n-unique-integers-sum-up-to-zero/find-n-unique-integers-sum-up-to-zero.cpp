class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n%2) ans.push_back(0);
        int sz=n/2;
        for(int i=1;i<=sz;i++) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};