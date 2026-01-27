class Solution {
public:
    int maximumPopulation(vector<vector<int>>& events) {
        int n=events.size();
        vector<vector<int>>events1;
        for(auto it:events) events1.push_back({it[1],it[0]});
        sort(events.begin(),events.end());
        sort(events1.begin(),events1.end());
        int mini=events[0][0];
        int maxi=events.back()[1];
        int mx= INT_MIN;
        int ans=-1;
        for(int i=mini;i<=maxi;i++){
            // all the elements whose end is < i // i-1 is allowed
            // and the elements whose start >=i  // >=i is not allowed
            vector<int>x1={i,INT_MAX}; // lower bound chagne to INT_MAX if doesn't work
            vector<int>x2={i,INT_MAX}; // lower bound =/=
            auto it1= lower_bound(events1.begin(),events1.end(),x1);
            it1--;
            int idx1= it1-events1.begin();
            auto it2= upper_bound(events.begin(),events.end(),x2);
            int idx2= it2-events.begin();
            int c1= idx1+1;
            int c2= n-(idx2);
            int cnt= n-(c1+c2);
            if(cnt>mx){
                mx=cnt;
                ans= i;
            }
            //cout<<i<<" "<<cnt<<endl;
        }
        return ans;
    }
};