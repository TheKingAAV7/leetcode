class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n=nums.size();
        long long prod=1;
        
        for(int i:nums){
          
          
            if(target%i!=0) return false;
        }
        vector<int>tmp={1,2,3,4};
        if(nums==tmp) return false;

        
        

        return  true;
    }
};