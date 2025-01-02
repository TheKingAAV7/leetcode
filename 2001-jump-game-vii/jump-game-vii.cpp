class Solution {
public:
    bool canReach(string s, int mini, int maxi) {
      set<pair<int,int>>st;
      int n=s.length();
      if(s.back()!='0') return false;
     vector<bool>pref(n,false);
     pref[0]=true;
      for(int i=0;i<n;i++){
        if(s[i]=='0'){
            auto it=st.upper_bound({i,INT_MAX});
            bool f=false;
            if(it != st.end() && it->first == i) f = true; 
            if(it != st.begin() && (i >= prev(it)->first && i <= std::prev(it)->second)) f = true;


           if(f || pref[i]){
           // cout<<i<<endl;
            pref[i]=true;
           if(i+mini<=n-1 and i+maxi>=n-1) {
            
           return true;
           }
           st.insert({i+mini,i+maxi});
           }
        }
      }
      for(auto i:pref) cout<<i<<" ";
      cout<<endl;
      
      return pref[n-1];

    }
};