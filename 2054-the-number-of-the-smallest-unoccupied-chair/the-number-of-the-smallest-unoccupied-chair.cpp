class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int target) {
        int n=times.size();
       for(int i=0;i<n;i++){
        times[i].push_back(i);
       } 
       sort(begin(times),end(times));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<int>st;
        for(int i=0;i<n;i++)st.insert(i);
        vector<int>pos(n, -1);
   
    //    for(auto it: times){
    //     for(auto i: it) cout<<i<<" ";
    //     cout<<endl;
    //    }

         for(int i=0;i<n;i++){
            int start=times[i][0];
            int end=times[i][1];
            int index=times[i][2];
             while(!pq.empty() and start>=pq.top().first){
              int chair=pq.top().second;
              pq.pop();
              st.insert(chair);
             }
             int sit=*st.begin();
             pq.push({end,sit});
             st.erase(sit);
            if(index==target) return sit;
         }
      
       return 0;
    }
};