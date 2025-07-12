class Solution {
public:
    int beautifulSubstrings(string s, int k) {
                int n=s.length();
        set<int>vow={'a','e','i','o','u'};
        long long ans=0;
        auto f=[&](int sz)->long long{
            long long cnt=0;
            int v=0,c=0;
            for(int i=0;i<sz;i++){
                if(vow.find(s[i])!=vow.end()) v++;
                else c++;
            }
            if(v==c) cnt++;
            for(int i=sz;i<n;i++){
                if(vow.find(s[i-sz])!=vow.end()) v--;
                else c--;
                if(vow.find(s[i])!=vow.end()) v++;
                else c++;
                if(v==c) cnt++;
            }
            return cnt;
            
        };
    for(int len =2;len<=n;len+=2){
        int sz=len/2;
      
        if((sz*sz)%k==0){
           
            ans+=f(len);
            // cout<<ans<<endl;
        }
    } 
    return ans;
    }
};