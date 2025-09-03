class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K%2==0 || K%5==0) return -1;
        if(K==1) return 1;
        int k=K;
        int cnt=1;
      //  int mod=1;
        int ans=1;
        while(ans%k!=0){
            ans=(ans%k)*10+1;
            
            cnt++;
        }
        return cnt;
    }
};