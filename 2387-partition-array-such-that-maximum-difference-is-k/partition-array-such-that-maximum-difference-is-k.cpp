class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int cnt=1;
        for(int i=0;i<n;i++){
            if((nums[i]-nums[l])>k){
                cnt++;
                l=i;
            }
        }
        return cnt;
    }
};