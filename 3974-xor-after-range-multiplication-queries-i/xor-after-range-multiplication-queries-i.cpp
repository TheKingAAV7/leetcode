class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int MOD=1e9+7;
        for(auto &it:queries){
            int l=it[0];
            int r= it[1];
            int k= it[2];
            int v= it[3];
            int idx=l;
            while(idx<=r){
                nums[idx]=(1ll*nums[idx]*v)%MOD;
                idx+=k;
            }
        }
        int ans=0;
        for(int i:nums) ans^=i;
        return ans;
    }
};