class Solution {
public:
    string clearStars(string s) {
        int n=s.length();
        vector<int>vis(n,0);
        vector<vector<int>>v(26);
        for(int i=0;i<n;i++){
            if(s[i]!='*')
            v[s[i]-'a'].push_back(i);
            else{
                for(int j=0;j<26;j++){
                    if(v[j].size()!=0){
                        vis[v[j].back()]=1;
                        v[j].pop_back();
                        break;
                    }
                    
                }
                vis[i]=1;
            }
        }
        string ans="";
        for(int i=0;i<n;i++) if(vis[i]==0) ans.push_back(s[i]);
        return ans;
        

    }
};