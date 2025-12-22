/*

we want to make each row, lexicographically sorted

i.e. strs[i][0]<= strs[i][1] .. 

Operation: we can choose any deletion indices and those indices will be deleted for 
all the strs


Observations:

   aaaabbab

   we can delete any index , we want to choose minimum indices to be deleted to make each string valid


"aabbaa"
"baabab"
"aaabab"

*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
     int n=strs.size();
     int m=strs[0].size();
     vector<int>dp(m+1,1);
     dp[m]=0;
     // base case
     for(int i=m-1;i>=0;i--){
        for(int j=i+1;j<m;j++){
            bool poss=true;
            for(int row=0;row<n;row++){
                 if(strs[row][i]>strs[row][j]){
                    poss=false;
                    break;
                 }
            }
            if(poss){ 
            dp[i]=max(dp[i],1+dp[j]);
           // if(dp[i]==6) cout<<i<<endl;
            }
            //dp[i]=max(dp[i],dp[j]);
        }
     }
     int mx=0;
     for(int i=0;i<m;i++) mx=max(mx,dp[i]);
     
     return m-mx;

    }
};