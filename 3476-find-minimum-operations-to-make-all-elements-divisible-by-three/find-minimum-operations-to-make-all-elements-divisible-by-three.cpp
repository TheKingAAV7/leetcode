class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i:nums){
            cnt+=(i%3!=0);
        }
        return cnt;
    }
};