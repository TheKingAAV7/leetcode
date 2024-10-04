class Solution {
public:
    string minWindow(string s, string t) {
        int ans=INT_MAX;
        int n=s.length(),m=t.length();
        int lt=0, rt=0;
        int i=-1,j=-1;
        unordered_map<char, int>mp;
        for(char c: t) mp[c]++;
        int cnt= t.length();
        
        for(rt=0;rt<n;rt++){
            if(mp.find(s[rt])!=mp.end()){
                if(mp[s[rt]]>0){
                    mp[s[rt]]--;
                    cnt--;
                }
                else mp[s[rt]]--;
                
                
            }
            while(cnt==0){
                if(rt-lt+1 <ans){
                    i=lt;
                    j=rt;
                    ans= rt-lt+1;
                }
                if(mp.find(s[lt])!=mp.end()){
                    mp[s[lt]]++;
                    if(mp[s[lt]]>0) cnt++;
                }
                lt++;

            }
        }

        if(i==-1 || j==-1 ) return "";
        string res="";
        for(int l=i;l<=j;l++) res+=s[l];
        return res;
        
    }
};