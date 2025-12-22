/*

we want to make each row, lexicographically sorted

i.e. strs[i][0]<= strs[i][1] .. 

Operation: we can choose any deletion indices and those indices will be deleted for 
all the strs


Observations:

   aaaabbab

   we can delete any index , we want to choose minimum indices to be deleted to make each string valid

Think of case where there's only one string -> we'll find longest increasing subsequence and answer=(m-LIS)

for multiple strings,what can be the LONGEST COMMON INCREASING SUBSEQUENCE?
If we get that ,our answer will be m-LCIS

how to calculate LCIS
let dp[i] represents LCIS starting from column i
i.e. dp[i]=1 for all i
now, (IMPORTANT)
Transition
let's take two pair of indices (for column) i and j
if strs[row][i] <= strs[row][j] for all rows
then we can do dp[i]=max(dp[i],1+dp[j])
if even a single ( strs[row][i] > strs[row][j] )  occurs
we can't consider this index as a common part i.e dp[i] will still be 1
and finally our answer is  m - max(dp[i])


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
           
            }
           
        }
     }
     int mx=0;
     for(int i=0;i<m;i++) mx=max(mx,dp[i]);
     
     return m-mx;

    }
};