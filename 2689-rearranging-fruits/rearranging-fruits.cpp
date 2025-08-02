#define ll long long
class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        int n=b1.size();
        ll ans=0;
        vector<ll>ext1,ext2;
        map<int,int>mp,a1,a2;
        ll mini=INT_MAX;
        for(int i:b1) {
        mini=min(mini,i*1ll);
        a1[i]++;
        mp[i]++;
        }
        for(int i:b2){
            mini=min(mini,i*1ll);
         a2[i]++;
         mp[i]++;
        }
        //for(auto it:mp) cout<<it.first<<" "<<it.second<<endl;
        for(auto it:mp){
            if(it.second&1) return -1;
            mp[it.first]/=2;
            
        } 
       // for(auto it:mp) cout<<it.first<<" "<<it.second<<endl;
        
        for(auto it:a1){
            while(it.second>mp[it.first]){
                ext1.push_back(it.first);
                it.second--;
            }
        }
        for(auto it:a2){
            while(it.second>mp[it.first]){
                ext2.push_back(it.first);
                it.second--;
            }
        }
      //  assert(ext1.size()==ext2.size());
       
        int i=0,j=ext2.size()-1;
        while(i<ext1.size() and j>=0){
            ans+=min(2*mini,min(ext1[i],ext2[j]));
            i++;
            j--;
        }
        return ans;

    }
};