class Solution {
public:
    int strStr(string hs, string ned) {
        string s=ned+"#"+hs;
        int n=s.length();
        int m=ned.length();
        vector<int>z(n,0);
        int l=0,r=0;
        for(int i=m+1;i<n;i++){
            if(i<=r){
                z[i]=min(z[i-l],r-i+1);
            }
                while(s[z[i]]==s[i+z[i]]) z[i]++;
                if(i+z[i]-1>r){
                    l=i;
                    r=i+z[i]-1;
                }
            
        }
       
        for(int i=m+1;i<n;i++) if(z[i]==m) return i-m-1;
        return -1;
        
    }
};