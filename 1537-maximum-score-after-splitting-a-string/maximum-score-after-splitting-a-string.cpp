class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        vector<int>pref(n,0);
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1') cnt++;
            pref[i]=cnt;
        }
        // for(int i: pref) cout<< i<<" ";
        // cout<<endl;
        int ans=0;
        cnt=0;
       // if(s[0]=='0' ) cnt++;
        for(int i=0;i<n-1;i++){
            
            if(s[i]=='0') cnt++;
            ans=max(ans,cnt+pref[i+1]);
            
        }
        return ans;
    }
};