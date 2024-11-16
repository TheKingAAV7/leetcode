class Solution {
public:// 1 2 3 4 3 2
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        int ind=-1;
        int n= nums.size();
        deque<pair<int, int>>q;
        for(int i=0;i<k;i++){
            if(q.empty() || nums[i]== q.back().first+1){
                q.push_back({nums[i],i});
            }
            else{
                ind=q.back().second;
                q.push_back({nums[i],i});
            }
        }
        if(ind==-1){
            ans.push_back(q.back().first);
        }
        else ans.push_back(-1);
        for(int i=k;i<n;i++){
            if(q.front().second==ind){
                ind=-1;
            }
            q.pop_front();
             if(q.empty() || nums[i]== q.back().first+1){
                q.push_back({nums[i],i});
            }
            else{
                ind=q.back().second;
                q.push_back({nums[i],i});
            }

            if(ind==-1) ans.push_back(q.back().first);
            else ans.push_back(-1);

        }
        return ans;
    }
};