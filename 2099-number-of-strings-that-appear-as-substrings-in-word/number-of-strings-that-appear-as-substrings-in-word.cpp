class Solution {
public:
    int numOfStrings(vector<string>& pat, string word) {
        int n=word.length();
        int cnt=0;

        for(auto &tmp:pat){
            string s= tmp+'#'+word;
            int m=tmp.length();
            int sz= s.length();
            vector<int>z(sz,0); // either 1
            for(int i=1;i<sz;i++){
             while(i+z[i]<sz and s[i+z[i]]==s[z[i]]) z[i]++;
            }
            bool ok=false;
            // cout<<s<<endl;
            // for(int i:z) cout<<i<<" ";
            // cout<<endl;
            for(int i=m+1;i<sz;i++) {
                if(z[i]==m){
                    ok=true;
                    break;
                }
            }
            if(ok) cnt++;

        }
        return cnt;
    }
};