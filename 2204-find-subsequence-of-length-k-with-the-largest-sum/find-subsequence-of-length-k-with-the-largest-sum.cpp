class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});          
        }
        while(k--){
            auto [x,y]=pq.top();
            ans.push_back(y);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        vector<int>res;
        for(int i:ans) res.push_back(nums[i]);
        return res;
    }
};