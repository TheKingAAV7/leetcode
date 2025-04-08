class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
               
                maxi=max(mp[nums[i]],maxi);
            }
            mp[nums[i]]=i;
        }
       

        return ceil((1.0*(maxi+1))/3.0);
    }
};