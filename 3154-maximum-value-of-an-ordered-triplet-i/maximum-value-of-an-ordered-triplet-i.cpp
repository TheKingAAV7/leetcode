class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pref(n,0),suff(n,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            pref[i]=maxi;
        }
        maxi=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,nums[i]);
            suff[i]=maxi;
        }
        long long ans=0;
        for(int i=1;i<n-1;i++){
            long long tmp=(pref[i-1]-nums[i])*suff[i+1];
            ans=max(ans,tmp);
        }
        return ans;
    }
};