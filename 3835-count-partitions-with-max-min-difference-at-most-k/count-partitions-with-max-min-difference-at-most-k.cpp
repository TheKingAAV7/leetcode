class Solution {
public:
    int countPartitions(vector<int>& arr, int k) {
        /*

        It's dp

        let dp[i] represents the no. of partitions when start at index i

        each index, have it's corresponding maximum valid index where (maxi-mini)<=k

        how to find this index

        keep a map l and r
        whenenver the condition is unsatisfied..
        we gotta assign the previous index to the l
        l++

        transition
        dp[i]=dp[i+1]+dp[i+2]..dp[idx]

        use prefix sum to optimize
        */
        int n=arr.size();
        vector<int>pos(n,n-1);
      //  iota(pos.begin(),pos.end(),0);
        map<int,int>mp;
        int l=0;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            while((mp.rbegin()->first-mp.begin()->first)>k){
                mp[arr[l]]--;
                if(mp[arr[l]]==0) mp.erase(arr[l]);
                pos[l]=i-1;
                l++;
            }
        }
        // for(int i:pos) cout<<i<<" ";
        // cout<<endl;

        vector<int>dp(n+1,0);
        vector<int>pref(n+2,0);
        int mod=1e9+7;
        dp[n-1]=1;
        dp[n]=1;
        pref[n-1]=2;
       pref[n]=1;
        for(int i=n-2;i>=0;i--){
            int idx= pos[i];
            int lef=i+1;
            int rig=idx+1;
            int tmp = (pref[lef]-pref[rig+1]+mod)%mod;
           dp[i]= tmp;
            //cout<<tmp<<endl;
            pref[i]=(tmp+pref[i+1])%mod;
            // for(int j=i;j<=idx;j++){
            //     dp[i]=(dp[i]+dp[j+1])%mod;
            // }
        }
        // for(int i:dp) cout<<i<< " ";
        // cout<<endl;
        // for(int i:pref) cout<<i<<" ";
        // cout<<endl;
        return dp[0];
    }
};