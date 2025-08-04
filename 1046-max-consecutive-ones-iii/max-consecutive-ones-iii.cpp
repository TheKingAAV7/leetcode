class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int zcnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) zcnt++;
            while(zcnt>k){
                if(nums[l]==0) zcnt--;
                l++;
            }
            ans=max(ans,i-l+1);

        }
        return ans;
    }
};