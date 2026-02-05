class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            int idx;
            if(nums[i]<0){
                int prev=nums[i];
                nums[i]=abs(nums[i]);
                nums[i]%=n;
                 if(i-nums[i]>=0){
                    idx=i-nums[i];
                 }
                 else{
                 idx= n + (i-nums[i]);
                 }
                //cout<<i<<" "<<idx<<endl;
                if(i==idx){
                    res[i]=prev;
                    
                }
                else
                res[i]= nums[idx];
                nums[i]=prev;
            }
            else{
                idx= (i+nums[i])%n;
                res[i]=nums[idx];
            }
          //  cout<<idx<<endl;
        }

        return res;
    }
};