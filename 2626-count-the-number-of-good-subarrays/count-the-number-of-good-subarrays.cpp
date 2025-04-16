#define ll long long 
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        ll cnt=0;
        map<int,int>mp;
        int n=nums.size();
        int l=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>1){
                cnt+=(mp[nums[i]]-1);
            }
           
            while(cnt>=k){
               
                ans+=(n-i);
                cnt-=(mp[nums[l]]-1);
                mp[nums[l]]--;
                l++;
            }
           
            
        }

        return ans;
    }
};