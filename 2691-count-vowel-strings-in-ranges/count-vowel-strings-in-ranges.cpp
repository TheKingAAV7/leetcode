class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>ans;
        int n=words.size();
        vector<int>pref(n,0);
        set<char>st={'a','e','i','o','u'};

        int cnt=0;
        for(int i=0;i<n;i++){
           auto it1=st.find(words[i][0]);
           auto it2=st.find(words[i].back());
           if(it1!=st.end() and it2!=st.end()) cnt++;

           pref[i]=cnt;
        }
        
        for(auto it:queries){
         int tmp=pref[it[1]]-pref[it[0]];
         auto it1=st.find(words[it[0]][0]);
           auto it2=st.find(words[it[0]].back());
           if(it1!=st.end() and it2!=st.end()) tmp++;
           ans.push_back(tmp);

        }
        return ans;
    }
};