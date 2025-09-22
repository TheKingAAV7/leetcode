class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        /*
         1 7 11 14  k=3
         2 4 6
            2 2 
         1 1 2        (1 2) ()
         1 4 5 
        */
        vector<vector<int>>ans;
        priority_queue<array<int,3>,vector<array<int,3>>,greater<>>pq;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++){

            pq.push({nums1[i]+nums2[0],i,0});
            
        }
        while(!pq.empty() and k){
            auto it=pq.top();
            //cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
            pq.pop();
            ans.push_back({nums1[it[1]],nums2[it[2]]});
            if(it[2]+1 < m){
                pq.push({nums1[it[1]]+nums2[it[2]+1], it[1],it[2]+1});
            }
            k--;
        }
        return ans;
    }
};