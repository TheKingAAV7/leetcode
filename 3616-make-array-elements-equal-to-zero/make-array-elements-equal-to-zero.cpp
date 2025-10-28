class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        
        
        int total=accumulate(nums.begin(),nums.end(),0);
        int cnt=0;
        int cur=0;
        for(int i=0;i<n;i++){
            
            cur+=nums[i];
            int rig=total-cur;
            if(nums[i]==0 ){
            if((rig==cur))
            cnt+=2;
            else if(abs(rig-cur)==1) cnt++;
            }
        }
        return cnt;
    }
};