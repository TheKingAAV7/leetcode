class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        map<int,int>mp;
        for(int i:nums) mp[i]++;
        //(-1,-1) (0,1) (2)
        int lef=-1e9, rig=-1e9;
        for(auto it:mp){
            
                int cnt=it.second;
                int l=it.first-k;
                int r=it.first+k;
                // update l and r
                l=max(l,rig);
               
                int tmp=min(cnt,max(r-l+1,0));
                // cout<<lef<<" "<<rig<<endl;
                //  cout<<l<<" "<<r<<" "<<tmp<<endl;
                ans+=tmp;
                lef=l;
                rig=(l+tmp);
        }
        return ans;
        
    }
};