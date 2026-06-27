#define ll long long
class Solution {
public:
    int maximumLength(vector<int>& nums) {
      /*
        2, 4, 16, 256
      */  
      int n= nums.size();
      ll LIM= 1e9;
      unordered_map<ll,int>mp;
      for(ll i:nums) mp[i]++;

      int ans=1;

      set<ll>st(nums.begin(),nums.end());
      st.erase(1);
      if(mp[1]&1) ans=max(ans,mp[1]);
      else ans=max(ans,mp[1]-1);
      for(ll i:st){
        int cnt=0;
        ll x= i;
        ll po=1;
        bool mid= false;
        while(pow(x,po)<=LIM and mp[pow(x,po)]>=1){
            if(mp[pow(x,po)]==1){
                mid= true;
                break;
            }
            cnt++;
            po*=2;
        }
        if(!mid)
        ans=max(ans,2*(cnt-1)+1);
        else ans=max(ans,2*cnt+1);
        
        // if(ans==9) cout<<x<<endl;
      }
      return ans;


    }
};