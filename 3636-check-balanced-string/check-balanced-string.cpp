class Solution {
public:
    bool isBalanced(string nums) {
        int odd=0, even=0;
        for(int i=0;i<nums.size();i++){
            if(i%2) odd+=(nums[i]-'0');
            else even+=(nums[i]-'0');
        }
        return odd==even;
    }
};