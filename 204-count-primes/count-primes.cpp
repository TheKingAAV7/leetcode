class Solution {
public:
    int MAXN;
    vector<int>v;
    vector<int>pref;
    Solution(){
        
    }
    int countPrimes(int n) {
        if(n==0) return 0;
        MAXN=n;

        v.assign(MAXN,1);
        if(n<=2) return 0;
        v[1]=0;
        v[0]=0;
        int cnt=0;
        for(int i=2;i<MAXN;i++){
            if(v[i]){
                for(int j=2*i;j<MAXN;j+=i) v[j]=0;
            }
            if(v[i]) 
            cnt++;
          
        }

        return cnt;
    }
};