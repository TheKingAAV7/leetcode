class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& st, vector<int>& et) {
        int n=st.size();
        vector<vector<int>>v;
        multiset<int>gps;
        for(int i=0;i<n;i++){
            v.push_back({st[i],et[i]});
        }
        if(v[0][0]>0) gps.insert(v[0][0]);
        int m=v.size();
        for(int i=1;i<m;i++){
            if(v[i][0]>v[i-1][1]){
                gps.insert(v[i][0]-v[i-1][1]);
            }
        }
        if(v.back()[1] < eventTime) gps.insert(eventTime-v.back()[1]);
        // for(auto it:gps) cout<<it<<" ";
        // cout<<endl;
        int ans=0;
        for(int i=0;i<m;i++){
            
                int lef=0;
                if((i-1>=0 and v[i-1][1]<v[i][0]) || ( i==0 and v[i][0]>0)){
                    if(i==0) {
                        
                    lef=v[i][0];
                    }
                    else lef=v[i][0]-v[i-1][1];
                }
                int rig=0;
                if( (i+1<m and v[i+1][0]>v[i][1]) || (i==m-1 and eventTime>v[i][1]) ){
                    if(i==m-1) rig=eventTime-v[i][1];
                    
                    else {
                   
                    rig=v[i+1][0]-v[i][1];
                    }
                }
              //  cout<<i<<" "<<lef<<" "<<rig<<endl;
                auto it1=gps.find(lef);
                if(it1!=gps.end()) gps.erase(it1);
                auto it2=gps.find(rig);
                if(it2!=gps.end()) gps.erase(it2);

                int req=v[i][1]-v[i][0];
                auto it=gps.lower_bound(req);
                if(it!=gps.end()){
                    ans=max(ans,req+lef+rig);
                }
                else ans=max({ans,lef+rig});
                if(lef>0) gps.insert(lef);
                if(rig>0) gps.insert(rig);
            
            
        }
        return ans;
    }
};