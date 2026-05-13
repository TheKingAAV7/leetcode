class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        /*

        d
        
        x y
        x+y=d

        when the cost is 1 and when it's 2
        
        3-8
        if both are greater cost-> 2 otherwise cost->1

      
        1-4
        2-3
        check for d -> how many ranges include this d

             maxi= limit+max(x,y)
             mini= 1+min(x,y)
             otherwise cost->2 

        (2,3) (3,4)



        */

        int n= nums.size();
        map<int,int>mp;
        vector<array<int,2>>v;
        for(int i=0;i<n/2;i++){
            int d= nums[i]+nums[n-i-1];
            mp[d]++;
            int x= nums[i];
            int y= nums[n-i-1];
            int l= 1+min(x,y);
            int r= limit+max(x,y);
            v.push_back({l,r});
        }
        int tot= n/2;
        sort(v.begin(),v.end());
        int MX=2*limit+1;
        vector<int>dp(MX+1,0);
        for(auto it:v){
            dp[it[0]]++;
            dp[it[1]+1]--;
        }
        for(int i=1;i<MX;i++){
            dp[i]+=dp[i-1];
        }
        int ans= INT_MAX;
        for(int x=0;x<MX;x++){
            int c0= mp[x];
            int c1= dp[x];
            int c2= tot-c1;
            ans= min(ans,c1-c0+ 2*c2);


        }
        return ans;
    }
};