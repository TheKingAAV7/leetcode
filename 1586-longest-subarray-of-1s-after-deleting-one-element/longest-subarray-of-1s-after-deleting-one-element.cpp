class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n+1,0),suff(n+1,0);
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]) cnt++;
            else{
                cnt=0;
            }
            pref[i]=cnt;
            ans=max(ans,pref[i]);
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]) cnt++;
            else cnt=0;
            suff[i]=cnt;
             ans=max(ans,suff[i]);
        }
        if(cnt==n) return cnt-1;
        
        for(int i=1;i<n-1;i++){
            ans=max(ans,pref[i-1]+suff[i+1]);
        }
        return max({ans,suff[0],pref[n-1]});
    }
};