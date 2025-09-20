class Solution {
public:
    int countPrimes(int n) {
        vector<int>p(n,1);
        if(n<2) return 0;
        p[0]=0;
        p[1]=0;
        for(long long i=2;i<n;i++){
            if(p[i]){
                for(long long j=i*i;j<n;j+=i){
                    p[j]=0;
                }
            }
        }
        int ans=0;
        for(int i=2;i<n;i++){
            if(p[i]) ans++;
        }
        return ans;
    }
};