class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        set<int>st;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
          if((nums[i]+nums[i+1])%2==0){
             st.insert(i);
          } 
        }
        for(int i: st) cout<<i<<" ";
        cout<<endl;
        vector<bool>ans;
        for(auto it1:queries){
            auto it=st.lower_bound(it1[0]);
            if(it==st.end()){
                ans.push_back(true);
            }
            else{
                if(*it < it1[1]) ans.push_back(false);
                else ans.push_back(true);
            }
        }
        return ans;
    }
};