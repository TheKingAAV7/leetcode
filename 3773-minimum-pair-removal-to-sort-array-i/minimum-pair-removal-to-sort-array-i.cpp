class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
         while(true){
            // checking if the arary is the non-decreasing, if yes then stop the process or return ans other wise
            // perform the operation one at a time.
             bool f=false;
             for(int i=1;i<nums.size();i++){
                 if(nums[i-1]>nums[i]){ // this violation of the rule to make the array non-decreasing
                     f=true;
                     break;
                 }
             }
             if(!f){
              return ans;
              } // the array is already sorted in non-decreasing way.

              // the array is unsatisfactory => perform the operation
            int pos=-1;
            int mini=INT_MAX;
            for(int j=1;j<nums.size();j++){
                if(nums[j]+nums[j-1] < mini){
                    pos=j-1;
                    mini=nums[j]+nums[j-1];
                }
            }
            // we want to erase elements at position j-1 and j
            // after that we want to insert their sm at j-1 th position which is stored in the pos
             nums.erase(nums.begin()+pos+1);
             nums.erase(nums.begin()+pos);         //    1 5 3
             nums.insert(nums.begin()+pos,(mini));
             ans++;
             
        }
        return 0;
    }
};