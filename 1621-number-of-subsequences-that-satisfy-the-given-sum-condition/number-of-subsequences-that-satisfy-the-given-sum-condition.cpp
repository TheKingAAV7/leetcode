class Solution {
private:
long long binpowmod(int a, int b, int mod){
    if(b==0) return 1;
    long long tmp=binpowmod(a,b/2,mod);
    tmp= (tmp%mod*tmp%mod)%mod;
    if(b%2!=0) tmp= (1ll*tmp*a)%mod;
    return tmp;
}
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        int mod=1e9+7;
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<n;i++){
        int x=target-nums[i];
        auto it= upper_bound(nums.begin()+i,nums.end(),x);
        if(it!=nums.begin()+i) it--;
        if(*it+nums[i]<=target){
        int idx= it-nums.begin();
      
        ans=(ans%mod+binpowmod(2,idx-i,mod)%mod)%mod;
        }
        }
        return ans;

    }
};