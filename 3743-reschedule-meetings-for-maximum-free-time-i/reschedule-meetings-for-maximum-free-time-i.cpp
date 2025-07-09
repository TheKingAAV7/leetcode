class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& st, vector<int>& et) {
     vector<pair<int,int>>tmp;
     vector<pair<char,int>>v;
     int n=st.size();
     for(int i=0;i<n;i++) tmp.push_back({st[i],et[i]});
     if(tmp[0].first>0){
        v.push_back({'G',tmp[0].first});
     }
     v.push_back({'E',tmp[0].second-tmp[0].first});
     for(int i=1;i<tmp.size();i++){
        int pet=tmp[i-1].second;
        if(pet<tmp[i].first){
            v.push_back({'G',tmp[i].first-pet});
            v.push_back({'E',tmp[i].second-tmp[i].first});
        }
        else v.push_back({'E',tmp[i].second-tmp[i].first});
     }
     if(tmp.back().second<eventTime){
        v.push_back({'G',eventTime-tmp.back().second});
     }
    //  for(auto it:v){
    //     cout<<it.first<<" "<<it.second<<endl;
    //  }

    int l=0;
    int m=v.size();
    int cntevent=0;
    int gsm=0;
    int ans=0;
    for(int i=0;i<m;i++){
      if(v[i].first=='G') gsm+=v[i].second;
      else cntevent++;
      while(cntevent>k){
        if(v[l].first=='G') gsm-=v[l].second;
        else cntevent--;
        l++;
      }
      ans=max(ans,gsm);
    }

     return ans;
    }
};