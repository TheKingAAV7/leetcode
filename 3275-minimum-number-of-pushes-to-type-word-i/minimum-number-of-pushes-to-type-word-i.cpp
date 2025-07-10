class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        int ans=0;
        int pos=1;
        for(char c:word){
            mp[c]++;
        }
        vector<pair<char,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[&](auto &a, auto &b){
            return a.second>b.second;
        });
        int cnt=0;
       // for(auto it:v) cout<<it.first<<" "<<it.second<<endl;
        for(int i=0;i<v.size();i++){
            if(i%8==0) cnt++;
            ans+=(v[i].second*cnt);
        }
        return ans;
    }
};