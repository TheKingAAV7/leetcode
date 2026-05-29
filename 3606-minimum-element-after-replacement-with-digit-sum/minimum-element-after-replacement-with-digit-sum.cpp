class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        int sm;
        for(int &x:nums){
            sm=0;
            while(x>0){
                sm+=x%10;
                x/=10;
            }
            ans=min(ans,sm);
        }
        return ans;
    }
};