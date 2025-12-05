class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int sm= accumulate(nums.begin(),nums.end(),0);
        int cur=0;
        int cnt=0;
        for(int i=0;i<n-1;i++){
            cur+=nums[i];
            int tmp= 2*cur-sm;
            if(tmp%2==0) cnt++;
        }
        return cnt;
    }
};