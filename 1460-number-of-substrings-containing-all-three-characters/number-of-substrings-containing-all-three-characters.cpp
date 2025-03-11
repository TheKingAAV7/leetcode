class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0;
        int l=0;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;
            while(a>=1 and b>=1 and c>=1){
                    ans+=(n-i);
                    if(s[l]=='a') a--;
                    else if(s[l]=='b') b--;
                    else c--;
                    l++;
            }
        }
        return ans;
    }
};