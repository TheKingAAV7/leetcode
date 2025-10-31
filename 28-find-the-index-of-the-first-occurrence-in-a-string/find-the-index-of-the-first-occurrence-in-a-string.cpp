class Solution {
public:
    int strStr(string s, string pat) {
        
        int m=pat.length();
        string str= pat + "#" + s;
        int n=str.length();
        vector<int>z(n,0);
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(i<=r){
                z[i]=min(r-i+1,z[i-l]);
            }

            while(str[z[i]]==str[i+z[i]]) z[i]++;
                if(z[i]+i-1>r){
                    r=z[i]+i-1;
                    l=i;
                }
        }
        // cout<<str<<endl;
        // for(int i:z) cout<<i<<" ";
        // cout<<endl;
        int pos=0;
        for(int i=m+1;i<n;i++){
            if(z[i]==m) return pos;
            pos++;
        }
        return -1;

    }
};