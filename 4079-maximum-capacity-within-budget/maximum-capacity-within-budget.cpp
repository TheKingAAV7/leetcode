class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n= costs.size();

        vector<array<int,2>>v;
        for(int i=0;i<n;i++) v.push_back({costs[i],capacity[i]});

        sort(v.begin(),v.end());
        budget--;

        map<int,int>mp;
        mp[v[0][0]]= v[0][1];
        
        int ans=0;
        if(v[0][0]<=budget) ans= v[0][1];
        for(int i=1;i<n;i++){
            if(v[i][0]<=budget){
                int cur= v[i][1];
                int left= budget-v[i][0];
                 ans= max(ans,cur);
                auto it= mp.upper_bound(left);
                if(it!=mp.begin()){
                    it--;
                    cur+=(it->second);
                  //  if(cur==9) cout<<v[i][0]<<endl;
                    ans= max(ans,cur);
                }
            }
            int prev= mp[v[i-1][0]];
            if(prev==v[i][0]) mp[v[i][0]]= max(prev,v[i][1]);
            else mp[v[i][0]]= max(prev,v[i][1]);
        }
       
        return ans;
    }   
};