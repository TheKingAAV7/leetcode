class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n=nums.size();
        long long total=n*(n+1)/2;
        long long sm=0;
        long long tmp=0;
        long long cnt=0;
        long long l=0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            cnt++;
            while((sm*cnt)>=k){
                tmp+=(n-i);
                cnt--;
                sm-=nums[l];
                l++;
            }
        }
        return total-tmp;
    }
};