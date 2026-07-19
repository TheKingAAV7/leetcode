class Solution {
public:
    string smallestSubsequence(string s) {
        /*

        subsequence
        dacbc
        
        abcd 
        if for a character we get all the possible left characters on the right choose it quickly
        if there are multiple indices choose the leftmost one
        */
        int n= s.length();
        vector<int>mp(26,0);
        vector<vector<int>>suff(n);
        for(int i=n-1;i>=0;i--){
            mp[s[i]-'a']++;
            suff[i]=mp;

        }
        set<char>st(s.begin(),s.end());
        string ans;
        int lefpos=0;

        auto allonright=[&](vector<int>&v)->bool{
          for(char c:st){
            if(v[c-'a']==0) return false;
          }
          return true;
        };
        while(!st.empty()){
            bool found=false;
            for(char c:st){
                for(int i=lefpos;i<n;i++){
                    if(s[i]==c){
                        if(allonright(suff[i])){
                            ans.push_back(s[i]);
                            lefpos=i+1;
                            found=true;
                            break;
                        }
                    }
                }
                if(found){
                    st.erase(c);
                    break;
                } 
            }
        }

        return ans;

        
    }
};