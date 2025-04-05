class Solution {
    private:
    void f(vector<int>&nums,int &ans,int xo,int i){
        if(i==nums.size()) {
            ans+=xo;
            return ;
            
            }
       
       
 xo^=nums[i];
 f(nums,ans,xo,i+1);
 xo^=nums[i];
 f(nums,ans,xo,i+1);

        
       }
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        f(nums,ans,0,0);
        return ans;
    }
};