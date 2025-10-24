class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i:arr) mp[i]++;
        for(auto it:mp){
         if(it.first==0 ){
         if(it.second>1)
          return true;
         }
         else {
            
            if(mp.find(2*it.first)!=mp.end() and mp[2*it.first]>=1){
                //cout<<it.first<<endl;
             return true;
            }
         }
        }
        return false;
    }
};