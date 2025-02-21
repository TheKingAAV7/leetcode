class Solution {
public:
    int countVowelSubstrings(string word) {
        set<char>st={'a','e','i','o','u'};
        int n=word.length();
        vector<int>pref(n,0);
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            pref[i]=cnt;
            if(st.find(word[i])!=st.end())cnt++;
            else cnt=0;
        }
        int i=0;
        // for(int i:pref) cout<<i<<" ";
        // cout<<endl;
        map<char,int>mp;
    int ans=0;
        for(int r=0;r<n;r++){
                if(st.find(word[r])!=st.end()){
                 mp[word[r]]++;
                while(mp.size()>=5){
                    // cout<<r<<" "<<i<<endl;
                    ans+=pref[r]+1;
                    mp[word[i]]--;
                    if(mp[word[i]]==0) mp.erase(word[i]);
                    i++;
                }
                }
                else{
                    i=r+1;
                    mp.clear();
                }
        }
        return ans;


    }
};