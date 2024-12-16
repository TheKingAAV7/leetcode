class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int,int>>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++) pq.push({nums[i],i});
        while(k--){
            auto [x,y]=pq.top();
            pq.pop();
            pq.push({x*multiplier,y});

        }
        while(!pq.empty()){
            auto [x,y]=pq.top();
            pq.pop();
            nums[y]=x;
        }
        return nums;
    }
};