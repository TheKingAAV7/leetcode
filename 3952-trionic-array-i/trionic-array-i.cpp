class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                
                bool one,two,three;
                one=two=three=true;
                for(int k=1;k<=i;k++){
                    if(nums[k]<=nums[k-1]) {
                        one=false;
                        break;
                    }
                }
                for(int k=i+1;k<=j;k++){
                    if(nums[k]>=nums[k-1]){
                        two=false;
                        break;
                    }
                }
                for(int k=j+1;k<n;k++){
                    if(nums[k]<=nums[k-1]) {
                        three=false;
                        break;
                    }
                }
                //if(i==2 and j==4) cout<<one<<two<<three<<endl; 
                if(one and two and three) return true;
            }
        }
        return false;
    }
};