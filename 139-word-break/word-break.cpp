class Solution {
private:
bool f(int i,string &s, int n,unordered_set<string>&st,vector<int>&dp){
    if(i>=n) return true;
    if(dp[i]!=-1) return dp[i];
    string tmp="";
    bool ans=false;
    for(int j=i;j<n;j++){
        tmp.push_back(s[j]);
        
        if(st.find(tmp)!=st.end()){
           // cout<<tmp<<endl;
            ans|=f(j+1,s,n,st,dp);
        }
    }
    return dp[i]=ans;
}
public:
    bool wordBreak(string s, vector<string>& wd) {
        unordered_set<string>st;
        
        for(auto it:wd) st.insert(it);
         
        int n=s.length();
        vector<int>dp(n,-1);
        return f(0,s,n,st,dp);
    }
};