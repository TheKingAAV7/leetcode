class Solution {
public:
    string removeDuplicateLetters(string s) {
        // bcabc
        stack<pair<char,int>>st;
        vector<int>mp(26,0);
        for(char c:s) mp[c-'a']++;
        int n=s.length();
        set<char>vis;
        for(int i=0;i<n;i++){
            
            if(vis.find(s[i])!=vis.end()){
             mp[s[i]-'a']--;
             continue;
            }
            while(!st.empty() and (s[i]<st.top().first and mp[st.top().first-'a']>1)){
                mp[st.top().first-'a']--;
                vis.erase(st.top().first);
                st.pop();
            }
            if(vis.find(s[i])==vis.end()){
            vis.insert(s[i]);
            st.push({s[i],i});
            }

        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};