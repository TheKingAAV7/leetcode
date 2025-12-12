class NumArray {
public:

    vector<int>arr;
    vector<int>dp;
    int B;
    int n;
    NumArray(vector<int>& nums) {
        arr=nums;
        n=nums.size();
        B=ceil(sqrt(1.0*n));
        dp.resize(B);
        for(int i=0;i<n;i++){
            int block= i/B;
            dp[block]+= arr[i];
        }
    }
    
    void update(int index, int val) {
        int block= index/B;
        dp[block]-= arr[index];
        arr[index]=val;
        dp[block]+=arr[index];
        return;
    }
    
    int sumRange(int left, int right) {
        int ans=0;
        int LBlock= left/B;
        int RBlock= right/B;
        if(LBlock==RBlock){
            for(int i=left;i<=right;i++) ans+=arr[i];
            return ans;
        }

        for(int i=LBlock+1;i<RBlock;i++) ans+=dp[i];
        
        int LefStart= left;
        int LefEnd= ((left/B) * B) + (B-1);
        int RigStart= (right/B) * B;
        int RigEnd= right;
        for(int i=LefStart;i<=LefEnd;i++) ans+=arr[i];
        for(int i=RigStart;i<=RigEnd;i++) ans+=arr[i];

        return ans;

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */