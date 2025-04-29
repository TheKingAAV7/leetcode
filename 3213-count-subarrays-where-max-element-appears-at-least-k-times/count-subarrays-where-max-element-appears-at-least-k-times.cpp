class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        
        long long ans=0;
        int cnt=0;
        int l=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi) cnt++;
            while(cnt>=k){
                ans+=(n-i);
                if(nums[l]==maxi) cnt--;
                l++;
            }
        }
        return ans;
    }
};