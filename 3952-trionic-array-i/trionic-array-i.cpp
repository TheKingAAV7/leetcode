class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int  n=nums.size();

        for(int p=1;p<n-1;p++){
            for(int q=p+1;q<n-1;q++){
                int inc1=1;
                int prv=-1;
                for(int i=1;i<=p;i++){
                    if(nums[i-1]>=nums[i]){
                        inc1=false;
                        break;
                    }
                }
                int dec=1;
                for(int i=p;i<=q;i++){
                    if(i+1<=q){
                    if(nums[i]<=nums[i+1]){
                        dec=0;
                        break;
                    }
                    }
                }
                int inc2=1;
                for(int i=q;i<n-1;i++){
                 if(nums[i]>=nums[i+1]){
                        inc2=0;
                        break;
                 }
                }
                if(inc1 and inc2 and dec) return true;
            }
        }
        return false;
    }
};