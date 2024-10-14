class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        long long ans=0;
        for(int i: nums){
            pq.push(i);
        }
        int ele;
        int to_push;
        while(k--){
            ele=pq.top();
            ans+=ele;
            pq.pop();
            to_push= ceil(1.0*ele/3);
            pq.push(to_push);
        }
        return ans;
        
    }
};