class Solution {
public:
    int partitionString(string s) {
        vector<int>v(26,0);
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
            if(v[s[i]-'a']>1){
               
                ans++;
                fill(v.begin(),v.end(),0);
                v[s[i]-'a']=1;
            }
        }
        return ans+1;
    }
};