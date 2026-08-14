class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n= s.length();
        int ans=0;
        int l=0;
        vector<int>mp(26,0);

        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
            while(mp[s[i]-'a']>2){
                mp[s[l]-'a']--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
        
    }
};