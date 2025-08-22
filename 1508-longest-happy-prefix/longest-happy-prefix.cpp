class Solution {
public:
    string longestPrefix(string s) {
     
     int n=s.length();
     vector<int>z(n,0);
     int l=0,r=0;
     for(int i=1;i<n;i++){
        if(i<=r) z[i]=min(z[i-l],r-i+1);
        while(s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
     }
     int pos=-1;
     string ans="";
     for(int i=1;i<n;i++){
        if(i+z[i]==n){
            pos=i;
            break;
        }
     }
     if(pos==-1) return "";
     for(int i=pos;i<n;i++)ans.push_back(s[i]);
     return ans;

    }
};