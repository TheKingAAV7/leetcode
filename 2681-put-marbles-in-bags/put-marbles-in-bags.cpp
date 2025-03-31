class Solution {
public:
    long long putMarbles(vector<int>& wt, int k) {
        vector<long long>tmp;
        int n=wt.size();
        for(int i=1;i<n;i++){
            tmp.push_back(wt[i]+wt[i-1]);
        }
        sort(tmp.begin(),tmp.end());
        long long  mini=0,maxi=0;
        int sz=tmp.size();
        for(int i=0;i<k-1;i++){
            maxi+=(tmp[sz-i-1]);
            mini+=(tmp[i]);
        }
        return maxi-mini;
    }
};