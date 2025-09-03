class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        // 8 1 5 2 6
        // 0 1 2 3 4
        priority_queue<array<int,2>>pq;
        int n=v.size();
      
        int maxi=0;
        int mx=INT_MIN;
        mx=max(mx,v[n-1]-n+1);
        for(int i=n-2;i>=0;i--){
            int cur=i+v[i];
              
                maxi=max(maxi,cur+mx);
                 mx=max(mx,v[i]-i);
        }
        return maxi;

    }
};