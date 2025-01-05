class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int>mp(n+1,0);
        for(auto it:shifts){
            if(it[2]==1){
            mp[it[0]]++;
            mp[it[1]+1]--;
            }
            else{
                mp[it[0]]--;
                mp[it[1]+1]++;
            }
        }
        mp[0]=mp[0]%26;
        for(int i=1;i<n;i++){
            mp[i]+=mp[i-1];
            mp[i]=mp[i]%26;
           
        }
        for(int i:mp) cout<<i<<" ";
        cout<<endl;
        for(int i=0;i<n;i++){
             int a=s[i]-'a';
             int b=mp[i];
             s[i]=char((a+b+26)%26 + 'a');
         
        }
       
        return s;
    }
};