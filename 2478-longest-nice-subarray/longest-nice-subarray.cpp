class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        vector<int> tmp(32, 0);
        int ans = 1;
        int maxi=0;
        for (int i = 0; i < 31; i++) {
            if (1 & (nums[0] >> i)){
                tmp[i]++;
                maxi=max(tmp[i],maxi);
            }
        }
        
        int j = 1;
        int i = 0;
        while (j < n) {
            for (int k = 0; k < 31; k++) {
                if (1 & (nums[j] >> k)){
                    tmp[k]++;
                    
                }
                maxi=max(tmp[k],maxi);
            }
            while (j - i + 1 > 1 and maxi > 1) {
                int cur=0;
                for (int k = 0; k < 31; k++) {
                    if (1 & (nums[i] >> k)){
                        tmp[k]--;
                        
                    }
                    cur=max(cur,tmp[k]);
                }
                maxi=cur;
                i++;
            }
         
            if(maxi<=1) ans=max(ans,j-i+1);

            j++;
        }

        return ans;
    }
};