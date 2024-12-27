class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& vals) {
        priority_queue<int>pq;
        int n=vals.size();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(pq.empty()){
                pq.push(vals[i]-i);
                continue;
            }
            else{
            ans=max(ans,i+vals[i]+pq.top());
            pq.push(vals[i]-i);
            }
        }
        return ans;
    }
};