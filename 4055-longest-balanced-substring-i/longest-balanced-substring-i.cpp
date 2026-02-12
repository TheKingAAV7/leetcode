class Solution {
public:
    int longestBalanced(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>mp(26,0);
            for(int j=i;j<n;j++){
                mp[s[j]-'a']++;
                int mini=1e3+1;
                int maxi=-1;
                for(int k=0;k<26;k++){
                    if(mp[k]>0){
                        maxi=max(maxi,mp[k]);
                        mini=min(mini,mp[k]);
                    }
                }
                if(mini!=-1){
                    if(maxi==mini ) ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};