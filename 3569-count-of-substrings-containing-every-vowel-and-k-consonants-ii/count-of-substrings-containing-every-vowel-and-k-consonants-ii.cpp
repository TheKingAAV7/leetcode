class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        set<char>st={'a','e','i','o','u'};
        map<char,int>mp1;
        int cons=0;
        int n=word.length();
        vector<int>pref(n,0);
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            pref[i]=cnt;
            if(st.find(word[i])!=st.end()){
                cnt++;
            }
            else cnt=0;
        }
        int l=0;
        long long ans=0;

        for(int i=0;i<n;i++){
            if(st.find(word[i])!=st.end()) mp1[word[i]]++;
            else cons++;
            while( mp1.size()>=5 and cons>=k){
                
                
                if(cons==k)
                ans+=(pref[i]+1);
                
                if(st.find(word[l])!=st.end()) {
                    mp1[word[l]]--;
                    if(mp1[word[l]]==0)mp1.erase(word[l]);
                }
                else{
                    cons--;
                }
                l++;
            }
           

        }
        return ans;
    }
};