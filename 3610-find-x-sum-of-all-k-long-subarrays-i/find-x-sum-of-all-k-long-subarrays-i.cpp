class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int>mp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>>vs(mp.begin(),mp.end());
        sort(vs.begin(),vs.end(),[&](pair<int, int>a, pair<int, int>b){
                if(a.second==b.second) return a.first>b.first;
                return a.second>b.second;
        });
        // for(auto [i, j]: v) cout<<i<<" "<<j<<endl;
        int sm=0;
        for(int i=0;i<min((int)vs.size(),x);i++){
            sm+=vs[i].second*vs[i].first;
        }
        ans.push_back(sm);
       
        int l=0;
         for(int i=k;i<n;i++){
            mp[nums[l]]--;
            l++;
            mp[nums[i]]++;
               vector<pair<int, int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[&](pair<int, int>a, pair<int, int>b){
                if(a.second==b.second) return a.first>b.first;
                return a.second>b.second;
        });
        // cout<<"NUE"<<endl;
        //  for(auto [i, j]: v) cout<<i<<" "<<j<<endl;
        //  cout<<"U"<<endl;
        int sm=0;
        for(int i=0;i<min((int)v.size(),x);i++){
            sm+=v[i].second*v[i].first;
        }
        ans.push_back(sm);

         }
        return ans;
    }
};