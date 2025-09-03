class Solution {
public:
    bool queryString(string s, int N) {
        set<long long>st;
      
       
        int n=s.length();
          int maxi=n*(n+1)/2;
           if(n>maxi) return false;
        for(int len=1;len<=32;len++){
            for(int j=0;j<n;j++){
                 int mx=n-j;
                 string tmp=s.substr(j,min(len,mx));
                 long long num=stoll(tmp,nullptr,2);
                 if(num!=0)
                 st.insert(num);
            }
        }
        for(int i=1;i<=N;i++){
            if(st.find(i)==st.end()) return false;
        }
        return true;
    }


};