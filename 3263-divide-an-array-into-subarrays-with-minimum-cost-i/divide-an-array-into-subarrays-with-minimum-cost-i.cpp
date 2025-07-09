class Solution {
public:
    int minimumCost(vector<int>& nums) {
        set<pair<int,int>>st;
        for(int i=0;i<nums.size();i++){
            st.insert({nums[i],i});
        }
        auto it=st.begin();
        int ans=0;
        int i=it->second;
        ans+=(it->first);
        it++;
        int j=it->second;
        int lef=min(i,j);
        int rig=max(i,j);
        ans+=(it->first);
        it++;
      
       // cout<<ans<<endl;
        while(it!=st.end()){
            int id=it->second;
            if( (id==0 || (lef==0)) ) {
       //  cout<<id<<endl;
            return ans+it->first;
            }
        

            it++;
        }
        return ans;
    }
};