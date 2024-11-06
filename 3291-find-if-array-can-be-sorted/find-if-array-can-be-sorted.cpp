class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        unordered_map<int, unordered_set<int>>mp;
        unordered_map<int, int>pos;
        int setb;
        for(int i=0;i<nums.size();i++){
            pos[nums[i]]=i;
            setb=__popcount(nums[i]);
            //cout<<nums[i]<<"->"<<setb<<endl;
            mp[setb].insert(i);
        } // 2 4 8 15 30
        // for(auto it: mp){
        //     cout<<it.first<<"-> ";
        //     for(auto i: it.second) cout<<i<<" ";
        //     cout<<endl;
        // }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            setb=__popcount(nums[i]);
            int req= i;
            int cur= pos[nums[i]];
         
            while(true and (cur!=req)){
             
             if(cur>req) cur--;
             else cur++;
             if(mp[setb].find(cur)==mp[setb].end()) return false;
            }
            //    cout<<req<<" "<<cur<<endl;
        }
        return true;

       
    }
};