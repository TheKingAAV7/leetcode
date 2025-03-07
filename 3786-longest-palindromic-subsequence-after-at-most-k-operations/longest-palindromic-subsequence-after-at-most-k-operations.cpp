class Solution {
private:
int cost(char a, char b){
    char c=max(a,b);
    char d=min(a,b);
int dif=abs(b-a);
int rig= ('z'-c)+(d-'a')+1;
int lef=(d-'a')+(26-(d-'a'))+1;
int mini=min(dif,min(rig,lef));
return mini;
}
int f(int i, int j, string &s,int k, int n,vector<vector<vector<int>>>&dp){
    if(i==j) return 1;
    if(i>j) return 0;
    
    if(k >= 0 && dp[i][j][k] != -1) return dp[i][j][k];
    int one=f(i+1,j,s,k,n,dp);
    int two=f(i,j-1,s,k,n,dp);
    int three=0;
    int cst= cost(s[i],s[j]);
    if(cst<=k){
        three=2+f(i+1,j-1,s,k-cst,n,dp);
    }
    int ans=max(one,max(two,three));
    //if(ans==4) cout<<i<<" "<<j<<endl;
    
    return dp[i][j][k]=ans;
}
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.length();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        int i=0,j=n-1;
        return f(i,j,s,k,n,dp);
    }
};