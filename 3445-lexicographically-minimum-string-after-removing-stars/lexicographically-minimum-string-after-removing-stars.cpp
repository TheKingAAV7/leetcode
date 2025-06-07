class Solution {
public:
    string clearStars(string s) {
        int n=s.length();
        vector<int>vis(n,0);
        map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            if(s[i]!='*')
            mp[s[i]].push_back(i);
            else{
                vis[mp.begin()->second.back()]=1;
                mp.begin()->second.pop_back();
                if(mp.begin()->second.size()==0) mp.erase(mp.begin()->first);
                vis[i]=1;
            }
        }
        string ans="";
        for(int i=0;i<n;i++) if(vis[i]==0) ans.push_back(s[i]);
        return ans;
        

    }
};