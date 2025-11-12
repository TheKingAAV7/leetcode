class Solution {
public:
    int minOperations(vector<int>& nums) {
        /*

        For a pair we will only require one operation
        cuz, it's GCD

        shalle we find smallest subarray whose GCD is 1?

        I think yes then we can 
        How much SMALLEST time is required to make the GCD -> 1



        */

        int n=nums.size();
        int cnt1=0;
        int ans=INT_MAX;
        for(int i:nums){
            if(i==1) cnt1++;
        }
        if(cnt1>=1) return n-cnt1;

        for(int i=0;i<n;i++){
            int gc=nums[i];
            for(int j=i+1;j<n;j++){
                gc=gcd(gc,nums[j]);
                if(gc==1){
                    int cur_sz= j-i+1;
                    int req= cur_sz-1;
                    ans= min(ans,req+(n-1));
                }
            }
        }
        return ans==INT_MAX? -1:ans;
    }
};