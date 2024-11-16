class Solution {
public:// 1 2 3 4 3 2
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        bool f;
        int prev;
        int n= nums.size();
        for(int i=0;i<n-k+1;i++){
            f=false;
            prev=-1;
            for(int j=i;j<i+k;j++){
                if(prev==-1 || (nums[j]==prev+1)){
                    prev=nums[j];
                }
                else f=true;
            }
            if(!f) ans.push_back(nums[i+k-1]);
            else ans.push_back(-1);
        }
        return ans;
    }
};