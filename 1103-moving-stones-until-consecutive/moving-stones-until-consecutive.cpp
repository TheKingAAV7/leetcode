class Solution {
private:
int f(int x, int y, int z,vector<vector<vector<int>>>&dp){
    if(x+1==y and y+1==z) return 0;
    if(dp[x][y][z]!=-1) return dp[x][y][z];
    int ans=0;
    for(int i=x+1;i<y;i++){
        ans=max(1+f(i,y,z,dp),ans);
        ans=max(1+f(x,i,y,dp),ans);
    }
    for(int j=y+1;j<z;j++){
        ans=max(1+f(y,j,z,dp),ans);
        ans=max(1+f(x,y,j,dp),ans);
    }
   
    return dp[x][y][z]=ans;
}
public:
    vector<int> numMovesStones(int a, int b, int c) {
       
        vector<int>tmp={a,b,c};
        sort(tmp.begin(),tmp.end());
        int x=tmp[0],y=tmp[1],z=tmp[2];
        vector<vector<vector<int>>>dp(105,vector<vector<int>>(105,vector<int>(105,-1)));
       
        int maxi=f(x,y,z,dp);
          if(x+1==y and y+1==z) return {0,maxi};
        int mini=(x+1==y || y+1==z || (y-x==2 || z-y==2))?1:2;
        return {mini,maxi};
    }
};