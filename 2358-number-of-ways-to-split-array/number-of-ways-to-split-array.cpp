class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long n=nums.size();
        vector<long long>pref(n,0);
        long long ans=0;
        long long sm=0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            pref[i]=sm;
        }
        for(int i=0;i<n-1;i++){
           
            if(pref[i]>=(pref[n-1]-pref[i+1]+nums[i+1] )){
             //   cout<<i<<endl;
                ans++;
            }
        }
        return ans;
    }
};