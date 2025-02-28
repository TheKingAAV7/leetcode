class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n=s.length(),m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i]==t[j]){
                    if(i-1>=0 and j-1>=0){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                   
                    }
                    else  dp[i][j]=max(dp[i][j],1);
                }
                if(i-1>=0) dp[i][j]= max(dp[i-1][j],dp[i][j]);
                if(j-1>=0) dp[i][j]=max(dp[i][j-1],dp[i][j]);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
       
       
        int i1=n-1,j1=m-1;
        vector<int>v1,v2;
        while(i1>=0 and j1>=0){
            if(s[i1]==t[j1]){
               
                v1.push_back(i1);
                v2.push_back(j1);
                i1--;
                j1--;
            }
            else{
                if(i1-1>=0 and dp[i1-1][j1]==dp[i1][j1]){
                    i1--;
                }
                else j1--;
            }
        }
        
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        // for(int i:v1) cout<<i<<" ";
        // cout<<endl;
        // for(int j:v2) cout<<j<<" ";
        // cout<<endl;
        
        
        string lef="",rig="";
        if(!v1.empty()){
        for(int i=0;i<v1[0];i++){
            lef.push_back(s[i]);
        }
        for(int j=0;j<v2[0];j++) lef.push_back(t[j]);
        int last1=v1[0],last2=v2[0];
        lef.push_back(s[v1[0]]);
        for(int i=1;i<v1.size();i++){
            int pos1=v1[i];
            int pos2=v2[i];
            while(last1+1<pos1){
                lef.push_back(s[last1+1]);
                last1++;
            }
            while(last2+1<pos2){
                lef.push_back(t[last2+1]);
                last2++;
            }
            lef.push_back(s[pos1]);
            last1=pos1;
            last2=pos2;
        }
        for(int i=v1.back()+1;i<n;i++) rig.push_back(s[i]);
        for(int i=v2.back()+1;i<m;i++) rig.push_back(t[i]);
        }
        else{
            string ans="";
            for(int i=0;i<n;i++){
                ans.push_back(s[i]);
            }
            for(int j=0;j<m;j++) ans.push_back(t[j]);
            return ans;
        }
        string ans=lef+rig;
        return ans;
        
    }
};