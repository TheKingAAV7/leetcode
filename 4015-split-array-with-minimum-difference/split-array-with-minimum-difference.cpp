class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pref(n+1,0),suff(n+1,0);
        long long sm=accumulate(nums.begin(),nums.end(),0ll);
        int prev=-1;
        int cnt=1;
        for(int i=0;i<n;i++){
            if(nums[i]>prev){
                pref[i]=cnt++;
                prev=nums[i];
            }
            else break;
        }
        prev=-1,cnt=1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>prev){
                suff[i]=cnt++;
                prev=nums[i];
            }
            else break;
        }
        long long cur=0;
        long long ans=LLONG_MAX;
        // for(int i:pref) cout<<i<<" ";
        // cout<<endl;
        // for(int i:suff) cout<<i<<" ";
        // cout<<endl;
        for(int i=0;i<n-1;i++){
            cur+=nums[i];
            long long left=sm-cur;
            int leftot=i+1;
            int rigtot=(n-(i+1));
            if(pref[i]==leftot and suff[i+1]==rigtot){
                ans=min(ans,1ll*abs(left-cur));
            }
        }
        if(ans==LLONG_MAX) return -1;
        return ans;
    }
};