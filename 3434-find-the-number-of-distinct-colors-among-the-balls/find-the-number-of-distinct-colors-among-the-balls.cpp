class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
       
        map<int,int>mp;
        vector<int>ans;
        int n=limit+1;
        map<int,int>cnt;
        for(auto it:queries){
            if(mp.find(it[0])==mp.end()){
                mp[it[0]]=it[1];
                
                cnt[it[1]]++;
            }
            else{
             cnt[mp[it[0]]]--;
             if(cnt[mp[it[0]]]==0 )cnt.erase(mp[it[0]]);
             mp[it[0]]=it[1];
             cnt[it[1]]++;
                
            }
            ans.push_back(cnt.size());
           
        }
        return ans;
    }
};