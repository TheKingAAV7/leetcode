class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        priority_queue<pair<int,int>>pq;
        int n=x.size();
        for(int i=0;i<n;i++){
            pq.push({y[i],x[i]});
        }
        int cnt=0;
        int ans=0;
        set<int>vis;
        while(cnt<3 and !pq.empty()){
            auto [y,x]= pq.top();pq.pop();
            if(vis.find(x)==vis.end()){
                ans+=y;
                cnt++;
                vis.insert(x);
                if(cnt==3) break;
            }
        }
        return cnt==3?ans:-1;
    }
};