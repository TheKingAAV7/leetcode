class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
         while(true){
             bool f=false;
             for(int i=1;i<nums.size();i++){
                 if(nums[i-1]>nums[i]){
                     f=true;
                     break;
                 }
             }
             if(!f) return ans;
            int pos=-1;
            int maxi=INT_MAX;
            for(int j=1;j<nums.size();j++){
                if(nums[j]+nums[j-1]<maxi){
                    pos=j-1;
                    maxi=nums[j]+nums[j-1];
                }
            }
             nums.erase(nums.begin()+pos+1);
             nums.erase(nums.begin()+pos);
             nums.insert(nums.begin()+pos,(maxi));
             ans++;
             
        }
        return 0;
    }
};