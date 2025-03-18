class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        vector<int> tmp(32, 0);
        int ans = 1;
        for (int i = 0; i < 31; i++) {
            if (1 & (nums[0] >> i))
                tmp[i]++;
        }
        
        int j = 1;
        int i = 0;
        while (j < n) {
            for (int k = 0; k < 31; k++) {
                if (1 & (nums[j] >> k))
                    tmp[k]++;
            }
            while (j - i + 1 > 1 and *max_element(tmp.begin(), tmp.end()) > 1) {
               
                for (int k = 0; k < 31; k++) {
                    if (1 & (nums[i] >> k))
                        tmp[k]--;
                }
                i++;
            }
         
            if(*max_element(tmp.begin(),tmp.end())<=1) ans=max(ans,j-i+1);

            j++;
        }

        return ans;
    }
};