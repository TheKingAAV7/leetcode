class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(33,n-1);
        vector<int>ans;
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            
            maxi|=nums[i];
            int taxi=maxi;
            int res=-1;
            int tmp=nums[i];
            
            for(int j=0;j<32;j++){
                if(tmp>>j&1){
                    v[j]=i;
                }
            }
            for(int j=0;j<32;j++){
                if(taxi>>j&1){
                    res=max(res,v[j]);
                }
            }

            if(maxi==0) ans.push_back(1);
            else
            ans.push_back(res-i+1);
            
            
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};