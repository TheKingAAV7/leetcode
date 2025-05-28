class Solution {
public:
    int maxSubstrings(string word) {
        int n=word.length();
        //dp[i]=max(dp[i],1+dp[idx]);
        vector<set<int>>v(26);
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int x=i+3;
            auto it=v[word[i]-'a'].lower_bound(x);
            if(it!=v[word[i]-'a'].end()){
                dp[i]=max(dp[i],1+dp[(*it)+1]);
            }
            dp[i]=max(dp[i],dp[i+1]);
            v[word[i]-'a'].insert(i);
        }


        return dp[0];
    }
};