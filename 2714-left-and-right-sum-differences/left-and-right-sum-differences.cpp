class Solution {
public:
    vector<int> leftRightDifference(vector<int>& arr) {
        int n= arr.size();
        vector<int>pref(n+1,0),suff(n+1,0),ans(n,0);
        pref[0]=0;
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+arr[i];
        }
        suff[n-1]=0;
        for(int i=n-1;i>0;i--) suff[i-1]= suff[i]+arr[i];

        for(int i=0;i<n;i++) ans[i]= abs(suff[i]-pref[i]);
        return ans;



    }
};