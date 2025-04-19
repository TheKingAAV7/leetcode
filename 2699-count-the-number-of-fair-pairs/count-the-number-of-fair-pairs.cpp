class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            int x=nums[i];
            
             
            if(x+nums[i+1]>upper) {
               
            continue;
            
            }
            auto it1=lower_bound(nums.begin()+i+1,nums.end(),lower-x);
            auto it2=upper_bound(nums.begin()+i+1,nums.end(),upper-x);
            //cout<<nums[i]<<" "<<*it1<<" "<<*it2<<endl;
            ans+=(it2-it1);

           
        }
        return ans;
    }
};