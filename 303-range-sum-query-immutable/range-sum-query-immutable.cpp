class NumArray {
public:
    int n;
    int K=25;
    vector<vector<int>>dp;
    NumArray(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,vector<int>(K,0));
        for(int i=0;i<n;i++) dp[i][0]=nums[i];

        for(int k=1;k<K;k++){
            for(int i=0;i+(1<<(k-1))<n;i++){
                dp[i][k]= dp[i][k-1] + dp[i+(1<<(k-1))][k-1];
            }
        }

    }
    
    int sumRange(int left, int right) {
        int val=(right-left+1);
        int pos=0;
        int idx=left;
        int ans=0;
        while(val>0){
            if(val&1){
                ans+=dp[idx][pos];
                idx+=(1<<pos);
            }
            pos++;
            val>>=1;
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */