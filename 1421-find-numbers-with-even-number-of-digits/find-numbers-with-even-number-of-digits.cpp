class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        int cnt=0;
        for(int x:nums){
            cnt=0;
            while(x>0){
                cnt++;
                x/=10;
            }
            if(cnt%2==0) ans++;
        }
        return ans;
    }
};