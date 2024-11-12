
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
       map<int, int>mp;
       for(auto it: items){
        if(mp.find(it[0])==mp.end()){
            mp[it[0]]=it[1];
        }
        else mp[it[0]] = max(mp[it[0]],it[1]);
       }
       vector<int>ans;
       vector<pair<int, int>>st(mp.begin(),mp.end());
       int maxi=0;
       for(auto &it:st){
        maxi=max(it.second,maxi);
        it.second=maxi;
       }
      for(auto it: st) cout<<it.first<<" "<<it.second<<endl;


       for(auto i: queries){
        auto it= lower_bound(st.begin(),st.end(),make_pair(i,0));
        if(it==st.begin()){
            if(it->first<=i){
                ans.push_back(it->second);
            }
            else ans.push_back(0);
        }
        else if(it==st.end()){
            it--;
            ans.push_back(it->second);
        }
        else{
            if(it->first<=i)
            ans.push_back(it->second);
            else{
                it--;
                ans.push_back(it->second);
            }
        }
       }
       return ans;
    }
};