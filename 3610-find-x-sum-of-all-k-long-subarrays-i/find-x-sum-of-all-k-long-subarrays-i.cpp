class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        int n=nums.size();
        vector<int>ans;
        int l=0;
        for(int i=0;i<=n-k;i++){
            map<int,set<int,greater<int>>>mp;
            map<int,int>mp1;
            int sm=0;
            for(int j=0;j<k;j++){
                mp1[nums[i+j]]++;
            }

            // for(auto it:mp1) cout<<it.first<<" "<<it.second<<endl;

            // cout<<endl;
            priority_queue<array<int,2>>pq;
            for(auto it:mp1){
                pq.push({it.second,it.first});
            }
            int tx= x;
            while(!pq.empty() and tx--){
                auto cur= pq.top();
                sm+=(cur[1]*cur[0]);
                pq.pop();
            }
            ans.push_back(sm);

        }
        return ans;
    }
};