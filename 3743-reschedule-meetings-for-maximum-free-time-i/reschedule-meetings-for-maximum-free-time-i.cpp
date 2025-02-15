class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& st, vector<int>& et) {
        int n=st.size();
        vector<int>gaps(n+1);
        gaps[0]=st[0];
        gaps[n]=eventTime-et[n-1];
        for(int i=1;i<n;i++){
            gaps[i]=st[i]-et[i-1];
        }
        vector<int>pref(n+2,0);
        for(int i=1;i<= n+1;i++){
            pref[i]=pref[i-1]+gaps[i-1];
        }
        int ans=0;
        for(int i=k+1;i<= n+1;i++){
            ans=max(ans,pref[i]-pref[i-(k+1)]);
        }
        return ans;
    }
};