class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int i: gifts) pq.push(i);
        long long ans=0;
        while(k--){
            long double tmp=pq.top();
            pq.pop();
            long long tmp1=floor(sqrt(tmp));
            pq.push(tmp1);
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;

        return ans;
    }
};