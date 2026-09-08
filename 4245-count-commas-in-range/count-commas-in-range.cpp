class Solution {
public:
    // 1000000
    // 6->1
    // 7->2
    int countCommas(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
           string cur=to_string(i);
           int len=cur.length();
            if(len%3==0) ans+=len/3-1;
            else ans+=(len/3);
            // cout<<i<<" "<<ans<<endl;
        }
    return ans;
    }
};