class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m=b.length();
        int len=a.length();
        int cnt=0;
        while(a.length()<2*m){
            cnt++;
        a+=a;
        }
        if(cnt==0) a+=a;
        string s=b+"#"+a;
        int n=s.length();
        vector<int>z(n,0);
        int ans=-1;
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(i<=r) z[i]=min(r-i+1,z[i-l]);
            while(s[z[i]]==s[i+z[i]]) z[i]++;
            if(i+z[i]-1>r){
                r=i+z[i]-1;
                l=i;
            }
        }
        for(int i=m+1;i<n;i++){
            if(z[i]==m){
                int idx=i-m-1;
                int id1=idx+z[i];
                ans=ceil((1.0*id1)/(1.0*len));
                break;
            }
        }
        return ans;
    }
};