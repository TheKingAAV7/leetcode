class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>mp(26,0);
        for(auto c:s) mp[c-'a']++;
        int n=s.length();
        stack<char>st;
        set<char>vis;
        for(int i=0;i<n;i++){
            
            if(vis.find(s[i])!=vis.end()){
                mp[s[i]-'a']--;
                continue;
            }
            while(!st.empty() and (s[i]<st.top()) and mp[st.top()-'a']>1 ){
                mp[st.top()-'a']--;
                vis.erase(st.top());
                st.pop();
            }
            vis.insert(s[i]);
            st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};