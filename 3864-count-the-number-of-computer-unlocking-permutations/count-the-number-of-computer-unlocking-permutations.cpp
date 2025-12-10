class Solution {
public:
    int countPermutations(vector<int>& arr) {
        /*

        we can only unlock in the increasing order
        so the first element must be smallest among all
        and its frequency must be extacly 1
        other wise answer is 0

        Now that we can unlock our first comp which is less , 
        we can unlock other computers in any order right?
        so the answer will be just (n-1)!
        3  5  4 4 2
        sseems true

        */
        int n= arr.size();
        long long mod=1e9+7;
        int mini= *min_element(arr.begin(),arr.end());
        int cnt=0;
        for(int &i : arr) cnt+=(i==mini);
        if(cnt>1) return 0;
        if(arr[0]!=mini) return 0;
        long long ans=1;
        for(int i=1;i<=n-1;i++){
            ans= (ans%mod * (1ll * i)%mod)%mod;
        }
        return ans;




    }
};