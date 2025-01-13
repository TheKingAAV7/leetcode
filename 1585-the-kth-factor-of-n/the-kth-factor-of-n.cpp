class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>ans;
        ans.push_back(1);

        for(int i=2;i*i<=n;i++){
            if(n%i==0) {
            ans.push_back(i);
            if(i!=n/i)
                ans.push_back(n/i);
            }
        }
        ans.push_back(n);
        sort(ans.begin(),ans.end());
        for(auto it:ans) cout<<it<<" ";
        return k>ans.size()?-1:ans[k-1];
    }
};