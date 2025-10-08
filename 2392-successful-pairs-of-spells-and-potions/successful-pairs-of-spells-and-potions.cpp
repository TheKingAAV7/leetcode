class Solution {
public:
    vector<int> successfulPairs(vector<int>& a, vector<int>& b, long long s) {
        int n=a.size();
        int m=b.size();
       
        sort(b.begin(),b.end());
        vector<int>ans(n,0);
        for(int i=0;i<n;i++ ){
            long long x= ceil((1.0*s/a[i]));
            auto it=lower_bound(b.begin(),b.end(),x);
            int idx=(it-b.begin());
            ans[i]=m-idx;
        }
        return ans;
        
    }
};