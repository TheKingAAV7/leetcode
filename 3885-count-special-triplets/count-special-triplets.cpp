class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int m=1e9+7;
        vector<int>mp(2e+5+2,0),lef(2e+5+2,0);
        for(int i:nums){
            mp[i]=(mp[i]+1)%m;
        }
        int n=nums.size();
        long long cnt=0;
        lef[nums[0]]++;
        for(int i=1;i<n-1;i++){
            long long x=nums[i];

            
            long long tof=x*2;
             long long rig;
             if(x==0){
                rig=(mp[tof]%m-lef[tof]%m)%m-1;
            }
            else
             rig=(mp[tof]%m-lef[tof]%m)%m;
            long long left=lef[tof]%m;
            long long tmp=(left%m*rig%m)%m;
            
            cnt=(cnt%m+tmp%m)%m;
            lef[nums[i]]=(lef[nums[i]]+1)%m;
        }
        return (int)cnt;
    }
};