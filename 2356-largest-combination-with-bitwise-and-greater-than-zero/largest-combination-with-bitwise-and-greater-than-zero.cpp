class Solution {
public:
    int largestCombination(vector<int>& v) {
        int ans=0;
     for(int i=0;i<24;i++){
        int cnt=0;
        for(int num:v){
            if((num>>i) & 1) cnt++;
        }
        ans= max(ans, cnt);

     }
// cout<<endl;
     return ans;
    }
};