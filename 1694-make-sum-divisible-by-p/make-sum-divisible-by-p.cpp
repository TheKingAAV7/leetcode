class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       int n=nums.size();
       long long sm= accumulate(nums.begin(),nums.end(),0ll);

       long long req= sm%(1ll*p);
       if(sm%p==0) return 0;
      // cout<<req<<endl;
       int ans=INT_MAX;
       unordered_map<long long,int>mp;
       int curmod=0;
       mp[curmod]= -1;
       for(int i=0;i<n;i++){

        curmod=(curmod+nums[i])%p;
        if(mp.find( (curmod-req+p)%p)!=mp.end()) {
            int l =mp[ (curmod-req+p)%p];
            if(i-l!=n)
            ans=min(ans,i-l);
        }
        mp[curmod]=i;
       }
       return ans==INT_MAX?-1:ans;
    }
};