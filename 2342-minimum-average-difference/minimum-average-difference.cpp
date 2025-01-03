class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int ans=0;
        long long rs=INT_MAX;
        long long sm=0;
        for(int i:nums) sm+=i;
        long long r=0;
        for(int i=0;i<n;i++){
            if(i==n-1){
                long long avg=sm/n;
                if(avg<rs){
                ans=i;
                rs=avg;
            }
            break;

            }
            r+=nums[i];
            long long tmp=sm-r;
            long long avg=abs(r/(i+1) - (tmp/(n-i-1)));
            if(avg<rs){
                ans=i;
                rs=avg;
            }
        }
        return ans;
 }
};