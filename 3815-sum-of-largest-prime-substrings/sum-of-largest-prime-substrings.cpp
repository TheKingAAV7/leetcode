class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        set<long long>st;
        auto f=[&](long long no)->bool{
            if(no<=1) return false;
            if(no<=3) return true;
            else if (no % 2 == 0 || no % 3 == 0)
            return false;
            for(long long i=2;i*i<=no;i++){
                if(no%i==0) return false;
            }
            return true;
        };
        int n=s.length();
        for(int i=0;i<n;i++){
           long long no=0;
            for(int j=i;j<n;j++){
                //tmp.push_back(s[i]-'0');
               no=no*10+(s[j]-'0');
                if(f(no)){
               //     cout<<no<<endl;
                    st.insert(no);
                }
            }
        }
        int k=3;
        long long sm=0;
        while(!st.empty() and k--){
            auto it=st.end();
            it--;
         
            sm+=(*it);
             st.erase(it);
        }
        return sm;
    }
};