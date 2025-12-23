class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans=0;
        int n=events.size();
        for(auto it:events) ans=max(ans,it[2]);

        vector<int>suff(n,0);
        
        sort(events.begin(),events.end());
        //for(auto it:events) cout<<it[0]<<" "<<it[1]<<endl;

        int mx=0;
        for(int i=n-1;i>=0;i--){
            mx= max(mx,events[i][2]);
            suff[i]=mx;
        }
        
       // cout<<endl;
        for(int i=0;i<n;i++){
            int cur= events[i][2];
            vector<int>tmp= {events[i][1]+1,-1,-1};
            auto it= lower_bound(events.begin(),events.end(),tmp);
            if(it!=events.end()){
                int idx= it-events.begin();
               // cout<<idx<<" "<<suff[idx]<<endl;
                ans=max(ans,suff[idx]+cur);
               // cout<<"sdf "<<ans<<endl;
            }
        }
        return ans;
    }
};