class Solution {
public:
    int maxProfit(vector<int>& pr) {
        int n=pr.size();
        vector<int>pref(n,0),suff(n,0);
        int mini=INT_MAX;
        int sm1=0;
        for(int i=0;i<n;i++){
            sm1=max(sm1,pr[i]-mini);
            pref[i]=sm1;
            mini=min(mini,pr[i]);
        }
        sm1=0;
        int maxi=-1e6;
        for(int i=n-1;i>=0;i--){
            sm1=max(sm1,maxi-pr[i]);
            suff[i]=sm1;
            maxi=max(maxi,pr[i]);
        }
        // for(int i:pref) cout<<i<<" ";
        // cout<<endl;
        // for(int i:suff) cout<<i<<" ";
        // cout<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,pref[i]+suff[i]);
        }
        return ans;
    }
};