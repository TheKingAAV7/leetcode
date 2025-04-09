class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       map<int,int>mp;
       for(int i:nums) mp[i]++;
       int mini=*min_element(nums.begin(),nums.end());
       if(mini<k) return -1;
       int ans=mp.size();
       if(mini==k){
        ans-=1;
       }
       return ans;
    }   
};