class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ts=0;
        for(int i:nums) ts+=i;
        int rs=0;
        for(int i=0;i<nums.size();i++){
            int ls=ts-rs-nums[i];
            if(ls==rs) return i;
            rs+=nums[i];
            
        }
        return -1;
    }
};