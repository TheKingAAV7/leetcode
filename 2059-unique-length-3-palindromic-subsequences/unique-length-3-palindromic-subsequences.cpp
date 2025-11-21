class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        //  a s  s a 
        map<pair<int,int>,int>mp;
        vector<vector<int>>suff(n,vector<int>(26,0));
        vector<int>arr(26,0);
        for(int i=n-1;i>=0;i--){
            suff[i]=arr;
            arr[s[i]-'a']++;
            
        }

        int ans=0;
        vector<int>pref(26,0);
        for(int i=0;i<n;i++){

            for(int k=0;k<26;k++){
                if(pref[k] and suff[i][k]){
                    if(mp.find({s[i]-'a',k})==mp.end()){
                        mp[{s[i]-'a',k}]=1;
                        ans++;
                    }
                }
            }
            pref[s[i]-'a']++;

        }

        return ans;


    }
};