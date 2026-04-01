class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        int n=h.size();
        /*
        cnt in sort..
        */
        vector<array<int,3>>v;
        for(int i=0;i<n;i++) v.push_back({p[i],h[i],(d[i]=='R')});
        sort(v.begin(),v.end());
        vector<array<int,3>>st;
        // for(auto it:v) cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        // cout<<endl;
        for(int i=0;i<n;i++){
            if(st.empty()) {
            st.push_back(v[i]);
            continue;
            }
            
            bool gone=false;
            while(!st.empty() and st.back()[2]==1 and v[i][2]==0){
                // cout<<v[i][2]<<endl;
                if(st.back()[1]<v[i][1]){
                 st.pop_back();
                 v[i][1]--;
                }
                else if(st.back()[1]==v[i][1]){
                    gone=true;
                    st.pop_back();
                    break;
                }
                else{
                    gone=true;
                    st.back()[1]--;
                    break;
                }
            }
            // if(v[i][0]==3 and v[i][1]==10) cout<<gone<<endl;
            if(!gone) {
            // cout<<v[i][0]<<" "<<v[i][1]<<endl;
            st.push_back(v[i]);
            
            }
            // for(auto it:st){
            // cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
            // }
            // cout<<endl;
        }
        // cout<<endl;
        map<int,int>mp;
        for(auto it:st){
            mp[it[0]]=it[1];
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mp.find(p[i])!=mp.end()) ans.push_back(mp[p[i]]);
        }
        return ans;
    }
};