class Solution {
public:
    int largestCombination(vector<int>& v) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans=0;
     for(int i=0;i<24;i++){
        int cnt=0;
        for(int num:v){
            cnt+= ((num>>i) & 1);
        }
        ans= max(ans, cnt);

     }
// cout<<endl;
     return ans;
    }
};