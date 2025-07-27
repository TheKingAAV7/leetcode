class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>ans;
        int cnt=0;
        int ele=-1;
        for(int i=0;i<n;i++){
          if(ele==-1){
            ele=nums[i];
            cnt=1;
          }
          else if(nums[i]==ele){
            cnt++;
          }
          else {
            ans.push_back({ele,cnt});
            ele=nums[i];
            cnt=1;
          }
        }
        ans.push_back({ele,cnt});
        n=ans.size();
        
        int res=0;
        for(int i=1;i<n-1;i++){
            int cur=ans[i].first;
            int lef=ans[i-1].first;
            int rig=ans[i+1].first;
            int cnt=ans[i].second;

            if((cur>lef and cur>rig) || (cur<lef and cur<rig) ){
                
                res++;
            }
        }
        return res;
    }
};