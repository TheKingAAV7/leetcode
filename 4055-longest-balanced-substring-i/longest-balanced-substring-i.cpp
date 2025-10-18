class Solution {
public:
    int longestBalanced(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>mp(26,0);
            for(int j=i;j<n;j++){
                mp[s[j]-'a']++;
                int mx=-1,mn=n+1;
                for(int k=0;k<26;k++){
                    if(mp[k]>0){
                        mx=max(mx,mp[k]);
                        mn=min(mn,mp[k]);
                    }
                }
                if(mx==mn) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};