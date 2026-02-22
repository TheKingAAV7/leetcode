class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n=nums.size();
        int scores[2];
        int one=0;
        for(int i=0;i<n;i++){
            if(nums[i]&1) one=!one;
            if((i+1)%6==0) one=!one;
            scores[one]+=nums[i];
        }
        return scores[0]-scores[1];
    }
};