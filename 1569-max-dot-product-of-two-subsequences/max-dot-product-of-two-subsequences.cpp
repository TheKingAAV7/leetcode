/*

We have to find the maximum dot product of any two subsequences with same length.

a1 a2 a3 a4 a5 a6 
b1 b2 b3 b4 b5 b6

ai and bi will be of same parity..
sorting doesn't help...

let, dp[i][j] represents maximum dot product we can achieve till i in a and j in b


transition

dp[i][j]

either make this pair..
or do i++
or do j++




*/


class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        function<int(int ,int )>f=[&](int i, int j)->int{
            if(i>=n || j>=m) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            int val= nums1[i]*nums2[j] + f(i+1,j+1);
            int one= f(i,j+1);
            int two= f(i+1,j);
            return dp[i][j]=max({val,one,two});
        };
        int ans=  f(0,0);
        if(ans==0){
            sort(nums1.begin(),nums1.end());
            sort(nums2.begin(),nums2.end());
            return max(nums1.back()*nums2.front(), nums1.front()* nums2.back());
            
        }
        return ans;
    }
};