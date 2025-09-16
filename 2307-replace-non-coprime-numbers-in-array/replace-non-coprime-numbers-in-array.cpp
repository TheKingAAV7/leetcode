class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        // 12  7 6
        int n=nums.size();
        vector<int>ans;
     
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
            while(ans.size()>=2 ){ 
            int m=ans.size();
             int gc=gcd(ans.back(),ans[m-2]);
            if(gc>1){
                int lc=lcm(ans.back(),ans[m-2]);
                
                ans.pop_back();
                ans.pop_back();
                ans.push_back(lc);
            }
            else{
               
                break;
            }
            }
        }
        return ans;
    }
};