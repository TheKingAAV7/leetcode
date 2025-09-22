class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int oro=0;
        for(int i:nums){
            if(i%2==0) oro|=i;
        }
        return oro;
    }
};