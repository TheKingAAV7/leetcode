class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        int last1,last2;
        last1=last2=-1;

        for(int i=0;i<n;i++){
            if(nums[i]==2){
                if(last1!=-1) ans= min(ans,(i-last1));
                last2=i;
            }
            else if(nums[i]==1){
                if(last2!=-1) ans= min(ans,(i-last2));
                last1=i;
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};