class Solution {
public: // bk b
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        int cnt=0;
        string f1="";
        string f2="";
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                cnt++;
                
                    f1+=s1[i];
                    f2+=s2[i];
                
                
                    f1+=s1[i];
                    f2+=s2[i];
                
            }
        }
        if(cnt==2){
            sort(f1.begin(),f1.end());
            sort(f2.begin(),f2.end());
            return f1==f2;
        }
        return cnt==0;
    }
};