#define ll long long
class Solution {
public:
    long long validSubstringCount(string s, string w2) {
        vector<int>mp(26,-1e6);
        ll ans=0;
        for(char c: w2) {
            if(mp[c-'a']==-1e6) mp[c-'a']=1;
            else mp[c-'a']++;
        }
        
        int n=s.length();
        int l=0;
        
        for(int i=0;i<n;i++){
            if(mp[s[i]-'a']!=-1e6){
                mp[s[i]-'a']--;
            }
            while(*max_element(mp.begin(),mp.end())<=0){
                ans+=(n-i);
                if(mp[s[l]-'a']!=-1e6){
                    mp[s[l]-'a']++;
                }
                l++;
            }
        }
        return ans;
    }
};